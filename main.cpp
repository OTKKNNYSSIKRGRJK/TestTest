#include<iostream>
#include<vector>
#include<utility>

template<typename T>
class Heap {
private:
	std::vector<T> Array{};
	int ArraySize{ 0 };

	inline int Get_ParentIndex(int _index) { return ((_index + 1) >> 1) - 1; }
	inline int Get_LeftChildIndex(int _index) { return ((_index + 1) << 1) - 1; }
	inline int Get_RightChildIndex(int _index) { return (_index + 1) << 1; }

	template<typename T>
	static inline bool IsGreater(T& _lhs, T& _rhs) { return _lhs > _rhs; }

	using CompFunc = bool(*)(T&, T&);
	CompFunc Comp{ &IsGreater };

public:
	explicit Heap() = default;
	explicit Heap(CompFunc _comp) : Comp(_comp) {}

	void Insert(const T _val) {
		Array.emplace_back(_val);
		++ArraySize;

		int newNodeIndex{ ArraySize - 1 }, parentIndex{ Get_ParentIndex(newNodeIndex) };
		while (newNodeIndex != 0 && Comp(Array[newNodeIndex], Array[parentIndex])) {
			std::swap(Array[parentIndex], Array[newNodeIndex]);
			newNodeIndex = parentIndex;
			parentIndex = Get_ParentIndex(newNodeIndex);
		}
	}

	// Extracts the root.
	int Extract(T& _val) {
		if (!Array.empty()) {
			_val = Array[0];

			std::swap(Array[0], Array[ArraySize - 1]);
			int index{ 0 };
			while (1) {
				int leftChildIndex{ Get_LeftChildIndex(index) }, rightChildIndex{ Get_RightChildIndex(index) };
				if (rightChildIndex < ArraySize) {
					// TBD 
				}
				else if (leftChildIndex < ArraySize) {
					// TBD
				}
				// Break if Array[index] is a leaf node.
				else { break; }
			}

			return true;
		}

		return false;
	}
};

int main() {
	Heap<int> heap{};

	std::cout << "BranchTest has been changed.\n";

	return 0;
}