#include<iostream>
#include<map>
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	map<int, int> m;
	ListNode *t = head;
	while(t != NULL) {
		bool exists = false;
		exists = m.count(t -> val);

		if(exists) {
			map<int, int>::iterator it;
			it = m.find(t -> val);

			int freq = it -> second;
			++freq;

			it -> second = freq;

		} else {
			m.insert({t -> val, 1});
		}

		t = t -> next;
	}

	t = head;
	ListNode *dummy = new ListNode(-1);
	dummy -> next = head;
	ListNode *prev = dummy;
	bool distinct = true;

	while(t != NULL) {
		int freq = m.find(t -> val);
		if(freq > 1) 
			distinct = false;

		if(distinct) {
			prev = t;
			t = t -> next;
		}
		else {
			while(freq != 0) {
			     t = t -> next;
			     --freq;
		        }

		        if(t != NULL) {
			      prev -> next = t;
			      if(prev == dummy) {
				      dummy -> next = t;         
				      prev = t;
			      }
		        }
		}
		
	}

	return dummy -> next;
	
}

int main() {
	return 0;
}
