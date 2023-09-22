#![allow(dead_code)]
#![allow(non_snake_case)]

use std::cmp::Ordering;
use std::fmt::Debug;
use std::ops::Deref;

pub enum Transversal {
    Pre,
    In,
    Pos,
}

#[derive(Debug)]
pub struct BST<T>
where
    T: Ord,
{
    left: Option<Box<BST<T>>>,
    value: Option<T>,
    right: Option<Box<BST<T>>>,
}

impl<T> Default for BST<T>
where
    T: Ord + Debug + Clone,
{
    fn default() -> Self {
        Self::new()
    }
}

impl<T> Clone for BST<T>
where
    T: Ord + Clone,
{
    fn clone(&self) -> Self {
        BST {
            left: self.left.clone(),
            value: self.value.clone(),
            right: self.right.clone(),
        }
    }
}

impl<T> BST<T>
where
    T: Ord + Debug + Clone,
{
    pub fn new() -> BST<T> {
        BST {
            left: None,
            value: None,
            right: None,
        }
    }

    pub fn print(&self) {
        fn print_t<T: Ord + Debug>(node: &BST<T>) {
            if let Some(ref value) = node.value {
                print!("{:?}", value);

                if let Some(ref left) = node.left {
                    print!("L(");
                    print_t(left);
                    print!(")");
                }

                if let Some(ref right) = node.right {
                    print!("R(");
                    print_t(right);
                    print!(")");
                }
            }
        }

        print!("(");
        print_t(self);
        println!(")");
    }

    pub fn iter(&self) -> impl Iterator<Item = &T> {
        BstIterator::new(self)
    }

    pub fn insert(&mut self, value: T) {
        if self.value.is_none() {
            self.value = Some(value);
        } else {
            match &self.value {
                None => (),
                Some(v) => {
                    let node = if value < *v {
                        &mut self.left
                    } else {
                        &mut self.right
                    };

                    match node {
                        Some(ref mut node) => node.insert(value),
                        None => {
                            let mut new_node = BST::new();
                            new_node.insert(value);
                            *node = Some(Box::new(new_node));
                        }
                    }
                }
            }
        }
    }

    pub fn search(&self, val: T) -> bool {
        match &self.value {
            Some(v) => match v.cmp(&val) {
                Ordering::Equal => true,
                Ordering::Greater => match &self.left {
                    Some(node) => node.search(val),
                    None => false,
                },
                Ordering::Less => match &self.right {
                    Some(node) => node.search(val),
                    None => false,
                },
            },
            None => false,
        }
    }

    pub fn minimum(&self) -> Option<&T> {
        match &self.left {
            Some(node) => node.minimum(),
            None => self.value.as_ref(),
        }
    }

    pub fn maximum(&self) -> Option<&T> {
        match &self.right {
            Some(node) => node.maximum(),
            None => self.value.as_ref(),
        }
    }

    pub fn to_vec(&self) -> Vec<T>
    where
        T: Clone,
    {
        let mut arr: Vec<T> = Vec::new();
        for i in self.iter() {
            arr.push(i.clone())
        }
        arr
    }

    pub fn find_maximum_above(&self, val: T) -> Option<&T> {
        match &self.value {
            Some(v) => match v.cmp(&val) {
                Ordering::Greater => match &self.left {
                    Some(node) => node.find_maximum_above(val),
                    None => None,
                },
                Ordering::Less => match &self.right {
                    Some(node) => {
                        let another_val = node.find_maximum_above(val);
                        match another_val {
                            Some(_) => another_val,
                            None => Some(v),
                        }
                    }
                    None => Some(v),
                },
                Ordering::Equal => Some(v),
            },
            None => None,
        }
    }

    pub fn find_maximum_below(&self, val: T) -> Option<&T> {
        match &self.value {
            Some(v) => match v.cmp(&val) {
                Ordering::Greater => match &self.left {
                    Some(node) => {
                        let another_val = node.find_maximum_below(val);
                        match another_val {
                            Some(_) => another_val,
                            None => Some(v),
                        }
                    }
                    None => Some(v),
                },
                Ordering::Less => match &self.right {
                    Some(node) => node.find_maximum_below(val),
                    None => None,
                },
                Ordering::Equal => Some(v),
            },
            None => None,
        }
    }

    pub fn depth_of(&self, val: T) -> Option<i16> {
        self.depth_of_helper(&val, 0)
    }

    fn depth_of_helper(&self, val: &T, depth: i16) -> Option<i16> {
        match &self.value {
            Some(v) => match val.cmp(v) {
                Ordering::Equal => Some(depth),
                Ordering::Less => match &self.left {
                    Some(l) => l.depth_of_helper(val, depth + 1),
                    None => None,
                },
                Ordering::Greater => match &self.right {
                    Some(r) => r.depth_of_helper(val, depth + 1),
                    None => None,
                },
            },
            None => None,
        }
    }

    pub fn num_of_nodes(&self) -> Option<u16> {
        match &self.value {
            Some(_) => {
                let ln = self
                    .left
                    .as_ref()
                    .map_or(0, |node| node.num_of_nodes().unwrap());
                let rn = self
                    .right
                    .as_ref()
                    .map_or(0, |node| node.num_of_nodes().unwrap());
                Some(1 + ln + rn)
            }
            None => None,
        }
    }

    pub fn max_heigth(&self) -> Option<u16> {
        match &self.value {
            Some(_) => {
                let ln = self
                    .left
                    .as_ref()
                    .map_or(0, |node| node.max_heigth().unwrap());
                let rn = self
                    .right
                    .as_ref()
                    .map_or(0, |node| node.max_heigth().unwrap());
                Some(1 + ln.max(rn))
            }
            None => None,
        }
    }

    fn internal_pl_helper(&self, depth: i16) -> Option<i16> {
        match &self.value {
            Some(_) => Some(
                depth
                    + self
                        .left
                        .as_ref()
                        .map_or(0, |node| node.internal_pl_helper(depth + 1).unwrap())
                    + self
                        .right
                        .as_ref()
                        .map_or(0, |node| node.internal_pl_helper(depth + 1).unwrap()),
            ),
            None => None,
        }
    }

    pub fn internal_path_length(&self) -> Option<i16> {
        self.internal_pl_helper(0)
    }

    // (esquerda-raiz-direita)
    fn transversal_in_ordem(&self) {
        if let Some(left) = &self.left {
            left.transversal_in_ordem();
        }
        if let Some(value) = &self.value {
            print!("{:?} ", value);
        }
        if let Some(right) = &self.right {
            right.transversal_in_ordem();
        }
    }

    // (ordem esquerda-direita-raiz)
    fn transversal_pos_ordem(&self) {
        if let Some(left) = &self.left {
            left.transversal_pos_ordem();
        }
        if let Some(right) = &self.right {
            right.transversal_pos_ordem();
        }
        if let Some(value) = &self.value {
            print!("{:?} ", value);
        }
    }

    // (raiz-esquerda-direita)
    fn transversal_pre_ordem(&self) {
        if let Some(value) = &self.value {
            print!("{:?} ", value);
        }
        if let Some(left) = &self.left {
            left.transversal_pre_ordem();
        }
        if let Some(right) = &self.right {
            right.transversal_pre_ordem();
        }
    }

    pub fn transversal(&self, format: Transversal) {
        print!("( ");
        match format {
            Transversal::Pre => self.transversal_pre_ordem(),
            Transversal::In => self.transversal_in_ordem(),
            Transversal::Pos => self.transversal_pos_ordem(),
        }
        println!(")");
    }
}

// declarative macro para criação de tree
macro_rules! newtree {
    ($($e: expr),*) => {
        {
            let mut x = BST::new();
            $(
                x.insert($e);
            )*
            x
        }
    };
}

#[derive(Debug, Clone)]
struct BstIterator<'a, T>
where
    T: Ord,
{
    stack: Vec<&'a BST<T>>,
}

impl<'a, T> BstIterator<'a, T>
where
    T: Ord + Debug + Clone,
{
    pub fn new(tree: &BST<T>) -> BstIterator<T> {
        let mut iter = BstIterator { stack: vec![tree] };
        iter.stack_push_left();
        iter
    }

    fn stack_push_left(&mut self) {
        while let Some(child) = &self.stack.last().unwrap().left {
            self.stack.push(child);
        }
    }
}

impl<'a, T> Iterator for BstIterator<'a, T>
where
    T: Ord + Debug + Clone,
{
    type Item = &'a T;
    fn next(&mut self) -> Option<&'a T> {
        if self.stack.is_empty() {
            return None;
        }
        let node = self.stack.pop().unwrap();
        if node.right.is_some() {
            self.stack.push(node.right.as_ref().unwrap().deref());
            self.stack_push_left();
        }
        node.value.as_ref()
    }
}

fn main() {
    let mut bst = newtree![8, 3, 10, 1, 6, 14, 4];
    bst.insert(7);

    bst.print();
    println!("{:?}", bst.depth_of(14));

    let v = bst.to_vec();
    println!("{}: {:?}", v.len(), v);
    println!("{:?}", bst.num_of_nodes());
    println!("{:?}", bst.search(10));
    println!("max: {:?}", bst.maximum());
    println!("min: {:?}", bst.minimum());
    println!("height: {:?}", bst.max_heigth());

    let num = 9;
    println!(
        "find_maximum_above {}: {:?}",
        num,
        bst.find_maximum_above(num)
    );
    println!(
        "find_maximum_below {}: {:?}",
        num,
        bst.find_maximum_below(num)
    );

    bst.insert(5);
    bst.print();

    println!("####################");
    print!("pre ordem (ordem raiz-esquerda-direita): ");
    bst.transversal(Transversal::Pre);

    print!("in  ordem (esquerda-raiz-direita......): ");
    bst.transversal(Transversal::In);

    print!("pos ordem (ordem esquerda-direita-raiz): ");
    bst.transversal(Transversal::Pos);
    println!("####################");

    println!("{:?}", bst.internal_path_length());
}
