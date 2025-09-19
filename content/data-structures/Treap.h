/**
 * Author: csq
 * Date: 2025-09-19
 * Source: kactl but modfied
 * Description: Segment tree but you can split and join segments
 * If it is not used as implicit treap, you should compare val 
 * during split and merge
 * Time: $O(\log N)$
 * Status: stress-tested
 */
#pragma once
struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1;
	Node(int val) : val(val), y(rand()) {}

	//auxilary info
    //int flip = 0,mn = 1e9,mnid = 0;
	void pull();
	void push();
	void apply();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::apply(){}
void Node::push(){}
void Node::pull(){
    push();
    c = cnt(l) + cnt(r) + 1;
	//merge nodes here
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
    n->push();
	if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
		auto [L,R] = split(n->l, k);
		n->l = R;
		n->pull();
		return {L, n};
	} else {
		auto [L,R] = split(n->r,k - cnt(n->l) - 1); // and just "k"
		n->r = L;
		n->pull();
		return {n, R};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
    l->push();
    r->push();
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		return l->pull(), l;
	} else {
		r->l = merge(l, r->l);
		return r->pull(), r;
	}
}

Node* ins(Node* t, Node* n, int pos) {
	auto [l,r] = split(t, pos);
	return merge(merge(l, n), r);
}

// Example application: move the range [l, r) to index k
void move(Node*& t, int l, int r, int k) {
	Node *a, *b, *c;
	tie(a,b) = split(t, l); tie(b,c) = split(b, r - l);
	if (k <= l) t = merge(ins(a, b, k), c);
	else t = merge(a, ins(c, b, k - r));
}
