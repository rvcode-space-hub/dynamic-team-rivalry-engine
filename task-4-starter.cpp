#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

class Item
{
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(
        std::string name,
        int quantity,
        float price) : name{std::move(name)},   
                       quantity{quantity},
                       price{price}
    {
    }

    std::string get_name() const
    {
        return name;
    }

    int get_quantity() const
    {
        return quantity;
    }

    void set_quantity(int new_quantity)
    {
        quantity = new_quantity;
    }

    float get_price() const
    {
        return price;
    }

    bool is_match(const std::string &other)
    {
        return name == other;
    }
};

class Inventory
{
private:
    std::vector<Item> items;
    float total_money;
    // int item_count;

    static void display_data(const Item &item)
    {
        std::cout << "\nItem name: " << item.get_name();
        std::cout << "\nQuantity: " << item.get_quantity();
        std::cout << "\nPrice: " << item.get_price();
    }

public:
    Inventory() : total_money(0) {}
    //         items{},
    //         total_money{0},
    //         item_count{0} {

    // }

    void add_item()
    {
        std::string name;
        int quantity;
        float price;

        cout << "\nEnter item name: ";
        cin >> name;

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter price: ";
        cin >> price;

        for (auto &item : items)
        {
            if (item.is_match(name))
            {
                item.set_quantity(item.get_quantity() + quantity);
                return;
            }
        }

        // new item add
        items.emplace_back(name, quantity, price);
    }

    //     std::cin.ignore();
    //     std::cout << "\nEnter item name: ";
    //     std::cin >> name;
    //     std::cout << "Enter quantity: ";
    //     std::cin >> quantity;
    //     std::cout << "Enter price: ";
    //     std::cin >> price;

    //     items[item_count] = new Item(name, quantity, price);
    //     item_count++;
    // }

    void sell_item()
    {
        string item_to_check;

        // std::cin.ignore();
        cout << "\nEnter item name: ";
        cin >> item_to_check;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].is_match(item_to_check))
            {
                remove_item(i);
                return;
            }
        }
        cout << "\nThis item is not in your Inventory";
    }

    // remove_item() fix

    void remove_item(int item_index)
    {
        int input_quantity;

        // Item *item = items[item_index];

        cout << "\nEnter number of items to sell: ";
        cin >> input_quantity;

        int quantity = items[item_index].get_quantity();

        // int quantity = item->get_quantity();

        if (input_quantity <= quantity)
        {
            float price = items[item_index].get_price();
            float money_earned = price * input_quantity;

            int new_quantity = quantity - input_quantity;
            items[item_index].set_quantity(new_quantity);

            // item->set_quantity(quantity - input_quantity);

            cout << "\nItems sold";
            cout << "\nMoney received: " << money_earned;

            total_money += money_earned;

            // FIX: quantity 0 → delete item

            if (new_quantity == 0)
            {
                items.erase(items.begin() + item_index);
            }
        }
        else
        {
            std::cout << "\nCannot sell more items than you have.";
        }
    }

    void list_items()
    {
        if (items.empty())
        {
            cout << "\nInventory empty.";
            return;
        }

        for (const auto &item : items)
        {
            display_data(item);
            cout << "\n";
        }
    }
};

// no need to modify anything here
int main()
{
    int choice;
    Inventory inventory_system;
    std::cout << "Welcome to the inventory!";

    while (1)
    {
        std::cout << "\n\nMENU\n"
                  << "1. Add new item\n"
                  << "2. Sell item\n"
                  << "3. List items\n"
                  << "4. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            inventory_system.add_item();
            break;

        case 2:
            inventory_system.sell_item();
            break;

        case 3:
            inventory_system.list_items();
            break;

        case 4:
            exit(0);

        default:
            std::cout << "\nInvalid choice entered";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            break;
        }
    }
}
