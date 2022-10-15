#pragma once

#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class Tree;

template <typename T>
using TreePtr = std::shared_ptr<Tree<T>>;

template <typename T>
class Tree {
private:
    T value_;
    std::vector<TreePtr<T>> children_;

public:
    T& value() { return value_; }
    const T &value() const { return value_; }
    std::size_t numberOfChildren() const { return children_.size(); }

    static TreePtr<T> createTree(T value) {
        auto root = TreePtr<T>(new Tree<T>);
        root->value_ = value;
        return root;
    }

    TreePtr<T> pushChild(T value) {
        auto newChild = TreePtr<T>(new Tree<T>);
        newChild->value_ = value;
        children_.push_back(newChild);
        return newChild;
    }

    TreePtr<T> insertChild(std::size_t childNumber, T value) {
        auto newChild = TreePtr<T>(new Tree<T>);
        newChild->value_ = value;
        children_.insert(children_.begin() + childNumber, newChild);
        return newChild;
    }

    TreePtr<T> pushTreeCopy(TreePtr<T> tree) {
        auto newChild = TreePtr<T>(new Tree<T>);
        newChild->value_ = tree->value_;
        for(TreePtr<T> oldChild : tree->children_) {
            newChild->pushTreeCopy(oldChild);
        }
        children_.push_back(newChild);
        return newChild;
    }

    TreePtr<T> insertTreeCopy(std::size_t childNumber, TreePtr<T> tree) {
        auto newChild = TreePtr<T>(new Tree<T>);
        newChild->value_ = tree->value_;
        for(TreePtr<T> oldChild : tree->children_) {
            newChild->pushTreeCopy(oldChild);
        }
        children_.insert(children_.begin() + childNumber, newChild);
        return newChild;
    }

    void removeChildTree(std::size_t childNumber) {
        if (numberOfChildren() <= childNumber) {
            throw std::runtime_error("invalid child");
        }
        children_.erase(children_.begin() + childNumber);
    }

    TreePtr<T> child(std::size_t childNumber) {
        if (numberOfChildren() <= childNumber) {
            throw std::runtime_error("invalid child");
        }
        return children_[childNumber];
    }
};