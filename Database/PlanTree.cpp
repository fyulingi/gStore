/*=============================================================================
# Filename: PlanTree.cpp
# Author: Linglin Yang
# Mail: fyulingi@gmail.com
=============================================================================*/


#include "PlanTree.h"
using namespace std;

string NodeJoinTypeStr(NodeJoinType node_join_type)
{
  switch (node_join_type) {
    case NodeJoinType::JoinANode: return "JoinANode";
    case NodeJoinType::JoinTwoTable: return "JoinTwoTable";
    case NodeJoinType::LeafNode: return "LeafNode";
  }
  return "NodeJoinType::No Exist";
}


PlanTree::PlanTree(int first_node) {
    root_node = new Tree_node(first_node);
}

PlanTree::PlanTree(PlanTree *last_plantree, int next_node) {
    root_node = new Tree_node();
    root_node->joinType = NodeJoinType::JoinANode;
    root_node->left_node = new Tree_node(last_plantree->root_node);
    root_node->right_node = new Tree_node(next_node);
}

PlanTree::PlanTree(PlanTree *left_plan, PlanTree *right_plan) {
    root_node = new Tree_node();
    root_node->joinType = NodeJoinType::JoinTwoTable;

    root_node->left_node = new Tree_node(left_plan->root_node);
    root_node->right_node = new Tree_node(right_plan->root_node);
}

void PlanTree::delete_tree_node(Tree_node *root_node) {
    if(root_node == nullptr){
        return;
    }

    delete_tree_node(root_node->left_node);
    delete_tree_node(root_node->right_node);
    delete root_node;
}

PlanTree::~PlanTree() {
    delete_tree_node(root_node);
}