#include <iostream>
#include <vector>

// stl�� ���ø��� ����ߴٸ� �� stl
// �ڷᱸ�����ø� != stl 
// stl�� �ڷᱸ�� stl�̶�� �մϴ�.
// C++�� ����

// stl�� ���Ե� �ڷᱸ���� ���ø� Ŭ�������� ���� �̴ϴ�.

// std �ڷᱸ���� �Ҽ� �ִٸ�
// ���� �Ȱ��� ���� �ϰ� �Ȱ��� ����� ���� Ŭ������ ����� ���°�.

// ����0 => HVector�� leck�� ���ֿͶ�  // leck�� �ʿ���� �޸𸮰� ���Ƽ� ����?
//         ���Կ����ڸ� ����ϸ� �����°� �������� ��������.
//         �̹� ������ �ڵ� �̹� array���� �ذ��� �Ѱſ���.

// ����1 => ���ø����� �ٲټ���.

using DataType = int;

template <typename T>
class HVector
{
public:                     
	HVector& operator=(const HVector& _Other)
	{
		size_t SmallSize = size() <= _Other.size() ? size() : _Other.size();

		for (size_t i = 0; i < SmallSize; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}
		return *this;
	}

	T& operator[](size_t _Index)  // int 
	{
		return ArrPtr[_Index];  // ArrPtr ����
	}

	size_t size()  // ũ��
	{
		return sizeValue;  // sizeValue ����
	}

	size_t capacity() // �뷮
	{
		return capacityValue;  // capacityValue ����
	}

	void push_back(const T& _Data)
	{
		// Ȯ���ؾ� �Ҷ��� �ֽ��ϴ�.
		if (sizeValue + 1 > capacityValue)  // sizeValue+1���� capacityValue���� ũ�ٸ�
		{
			reserve((int)((capacityValue * 1.5) + 1));  // capacityValue���� * 1.5��+1�� �غ��صֶ�
		}

		ArrPtr[sizeValue] = _Data;  
		sizeValue += 1;
	}

	void reserve(size_t _capacity)
	{
		T* PrevPtr = ArrPtr;  // int�������� PrevPtr�� ArrPtr���̴�.

		// 1ȸ�� new�� �Ͼ�ٸ� 1ȸ�� delete�� ��򰡿� �����ؾ� �Ѵ�.
		ArrPtr = new T[_capacity];  // new int��[_capacity]���� ����Ų��.

		// ���ʿ� �ѹ��� ���� nullptr �̾������̴�.
		if (nullptr != PrevPtr)  // ���� PrevPtr�� nullptr�� ����Ű�� �ʴ´ٸ�
		{
			for (size_t i = 0; i < sizeValue; i++)  // 
			{
				ArrPtr[i] = PrevPtr[i];
			}
			delete PrevPtr;  
			PrevPtr = nullptr;
		}

		capacityValue = _capacity;
	}
	
	
	~HVector()  // �Ҹ���
	{
		if (nullptr != ArrPtr)  // ArrPtr�� nullptr�� ����Ű�� �ʴ´ٸ�
		{
			delete ArrPtr;  // ArrPtr�� delete�ϰ�
			ArrPtr = nullptr;  // ArrPtr�� nullptr�� ����Ű�� �ض�
		}
	}

	T* ArrPtr = nullptr;
private:
	int sizeValue = 0;  // sizeValue ���� 0
	int capacityValue = 0;  // capacityValue ���� 0
	  // int�������� ArrPtr�� nullptr�� ����Ŵ
};





int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//{
	//	//int Arr[10];

	//	//Arr[-1] = 20;
	//}

	//{
	//	// ���Ե� �ȵ�
	//	// ������ ������� �˼� ����.
	//	// int Arr[10];

	//	// �迭�� ���� ���� �޸� �����Դϴ�.
	//	// ���� ���� �ڷᱸ�� �Դϴ�.
	//	// ������ ���� ������.
	//	// ���� ��� ��κ��� ��Ȳ���� 
	//	// �迭�� ��ü�ϴ� �ڷᱸ���� Ŭ�����Դϴ�.
	//	// vector => 
	
	//	std::vector<int> Arr = std::vector<int>(10);
	//	for (int i = 0; i < Arr.size(); i++)
	//	{
	//		Arr[i] = i;
	//	}

	//	//for (int i = 0; i < Arr.size(); i++)
	//	//{
	//	//    std::cout << Arr[i] << std::endl;
	//	//}

	//	// Arr.resize(20);

	//	// Arr.reserve();
	//	// Arr.resize();
	//	// Arr.size();
	//}

	//{
	//	// �迭ó�� ���°� �ƴ϶�.
	//	// �Ϲ����� Ȯ���� �ڷᱸ��ó�� ����ϴ¹�
	//	std::vector<int> Arr;

	//	// �̸� �迭�� �׸�ŭ �Ҵ��� ���°��� �ǹ��մϴ�.
	//	// �����긦 ������� �����Ÿ� ���͸� �־���?
	//	// Arr.reserve(10);

	//	// ���ʹ�
	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		Arr.push_back(i);
	//		std::cout << "size : " << Arr.size() << std::endl; // �����Ǽ�
	//		std::cout << "capacity : " << Arr.capacity() << std::endl; // �޸��� ũ��
	//	}

	//	// Arr[-1];
	//	// Arr.operator[](-1);

	//	for (size_t i = 0; i < Arr.size(); i++)
	//	{
	//		std::cout << Arr[i] << std::endl;
	//	}
	//}

	// ���⸦ �ǵ��� ������.
	{
		HVector<DataType> Arr;  // Hvector Ŭ������ Arr
		// ���ο� 123
		// Arr.reserve(10);
		for (size_t i = 0; i < 10; i++)  
		{
			Arr.push_back(i);
			//std::cout << "size : " << Arr.size() << std::endl; // �����Ǽ�
			//std::cout << "capacity : " << Arr.capacity() << std::endl; // �޸��� ũ��
		}

		for (size_t i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}

		HVector<DataType> Arr0;  // Hvector Ŭ������ Arr0

		// ���� �ذ��ϴ� ���� �����̴ϴ�.
		// �������� ���簡 �̷������ �ϼ���.
		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}
}