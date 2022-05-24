template <typename T>
class ListNode
{
    T data;

public:
    ListNode(T data, ListNode<T>* pNext)
    {
        this->data = data;
        this->pNext = pNext;
    }

    T getData() { return this->data; }
    ListNode<T>* pNext;
};

template <typename T>
class List
{
    int size;
    ListNode<T>* head;

public:
    List()
    {
        this->size = 0;
        this->head = nullptr;
    }

    void pushBack(T data)
    {
        if (head == nullptr)
            head = new ListNode<T>(data, nullptr);
        else
        {
            ListNode<T>* cur = this->head;
            while (cur->pNext != nullptr)
                cur = cur->pNext;
            cur->pNext = new ListNode<T>(data, nullptr);
        }
        size++;
    }

    ListNode<T>* getHead() { return this->head; }
    int getSize() { return this->size; }
};
