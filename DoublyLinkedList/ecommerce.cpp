#include <iostream>
using namespace std;
#include <vector>
struct Node
{
public:
    string name;
    string des;
    int item_id;
    int price;
    int quantity;
    Node *prev;
    Node *next;
    Node(string name, string des, int item_id, int price, int quantity)
    {
        this->name = name;
        this->des = des;
        this->item_id = item_id;
        this->price = price;
        this->quantity = quantity;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    vector<Node> cart;
    LinkedList()
    {
        head = tail = NULL;
    }
    void add_at_start(string name, string des, int item_id, int price, int quantity)
    {
        Node *newNode = new Node(name, des, item_id, price, quantity);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Product is added to list " << endl;
            return;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            cout << "Product is added to list " << endl;
        }
    }
    void add_at_End(string name, string des, int item_id, int price, int quantity)
    {
        Node *newNode = new Node(name, des, item_id, price, quantity);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Product  is added To list " << endl;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cout << "Product is added to List " << endl;
        }
    }
    // display
    void display_Product()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "-------------------" << endl;
            cout << "name :" << temp->name << endl;
            cout << "Description : " << temp->des << endl;
            cout << "ID : " << temp->item_id << endl;
            cout << "price :" << temp->price << endl;
            cout << "Quantity : " << temp->quantity << endl;
            cout << "-------------------" << endl;
            temp = temp->next;
        }
    }
    // Delete by value
    void delete_by_value(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->item_id != id)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Product is not found" << endl;
            return;
        }

        if (temp->item_id == id)
        {
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }
            delete temp;
            cout << "Product is deleted from the list " << endl;
            return;
        }
        if (temp == tail)
        {
            temp = tail->prev;
            temp->next = NULL;
            delete tail;
            tail = temp;
            cout << "Product is deleted from the list " << endl;
            return;
        }

        Node *del = temp;
        temp->prev->next = del->next;
        temp->next->prev = del->prev;
        delete del;
        cout << "Produc deleted from the list " << endl;
    }
    // Add to cart
    void add_to_cart(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->item_id == id)
            {
                if (temp->quantity > 0)
                {
                    for (int i = 0; i < cart.size(); i++)
                    {
                        if (cart[i].item_id == id)
                        {
                            cart[i].quantity++;
                            temp->quantity--;
                            cout << "Porduct is added to cart list " << endl;
                            return;
                        }
                        temp = temp->next;
                    }
                    Node item(temp->name, temp->des, temp->item_id, temp->price, temp->quantity);
                    cart.push_back(item);
                    cout << "Product is added to cart list " << endl;
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Product is not found " << endl;
    }
    // show cart list
    void show_cart_list()
    {
        if (cart.size() <= 0)
        {
            cout << "list is empty " << endl;
            return;
        }
        int total = 0;
        for (int i = 0; i < cart.size(); i++)
        {
            cout << "ID: " << cart[i].item_id << endl;
            cout << "Name: " << cart[i].name << endl;
            cout << "Description: " << cart[i].des << endl;
            cout << "Quantity: " << cart[i].quantity << endl;
            cout << "Price: " << cart[i].price << endl;
            cout << "--------------------------" << endl;
            total += cart[i].price;
        }
        cout << "Total Price :" << total << endl;
    }
    void remove_From_cart(int id)
    {
        if (cart.size() <= 0)
        {
            cout << "Cart is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->item_id == id)
            {
                for (int i = 0; i < cart.size(); i++)
                {
                    if (cart[i].item_id == id)
                    {
                        cart[i].quantity --;
                        temp->quantity++;
                        cart.erase(cart.begin()+i);
                        cout << "Product deleted from the list "<< endl;
                        return;
                    }
                }
            }
            temp = temp->next;
        }
        cout << "Product not found in the list" << endl;
    }
};
int main()
{
    LinkedList obj;
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "      🛒 INVENTORY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Product at Start\n";
        cout << "2. Add Product at End\n";
        cout << "3. Display Products\n";
        cout << "4. Delete Product\n";
        cout << "5. Add To Cart\n";
        cout << "6. Show Cart\n";
        cout << "7. Remove From Cart\n";
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name, des;
        int id, price, quantity;

        switch(choice)
        {
            case 1:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Description: ";
                cin >> des;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                obj.add_at_start(name, des, id, price, quantity);
                break;

            case 2:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Description: ";
                cin >> des;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                obj.add_at_End(name, des, id, price, quantity);
                break;

            case 3:
                obj.display_Product();
                break;

            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                obj.delete_by_value(id);
                break;

            case 5:
                cout << "Enter ID to add to cart: ";
                cin >> id;
                obj.add_to_cart(id);
                break;

            case 6:
                obj.show_cart_list();
                break;

            case 7:
                cout << "Enter ID to remove from cart: ";
                cin >> id;
                obj.remove_From_cart(id);
                break;

            case 0:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}