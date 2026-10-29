#include <iostream>
#include <string>
using namespace std;

class Member
{
public:
    int id;
    string name;
    string phone;
    string plan;
    int months;
    int daysLeft;
    double paid;
};

class Gym
{
    Member m[100];
    int total = 0;
    double income = 0;

public:
    void registerMember()
    {
        if (total >= 100)
        {
            cout << "Gym member limit reached!\n";
            return;
        }

        cout << "Enter member ID: ";
        cin >> m[total].id;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == m[total].id)
            {
                cout << "Member ID already exists!\n";
                return;
            }
        }

        if (m[total].id <= 0)
        {
            cout << "Invalid member ID!\n";
            return;
        }

        cout << "Enter member name: ";
        cin >> ws;
        getline(cin, m[total].name);

        cout << "Enter phone number: ";
        getline(cin, m[total].phone);

        m[total].plan = "Not selected";
        m[total].months = 0;
        m[total].daysLeft = 0;
        m[total].paid = 0;

        total++;

        cout << "Member registered successfully!\n";
    }

    void showMembers()
    {
        if (total == 0)
        {
            cout << "No members registered yet.\n";
            return;
        }

        cout << "\n===== GYM MEMBERS =====\n";

        for (int i = 0; i < total; i++)
        {
            cout << "\nMember ID: " << m[i].id;
            cout << "\nName: " << m[i].name;
            cout << "\nPhone: " << m[i].phone;
            cout << "\nPlan: " << m[i].plan;
            cout << "\nDays left: " << m[i].daysLeft;
            cout << "\nTotal paid: Rs. " << m[i].paid << endl;
        }
    }

    void updateMember()
    {
        int id;

        cout << "Enter member ID to update: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == id)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Member not found!\n";
            return;
        }

        cout << "Enter new name: ";
        cin >> ws;
        getline(cin, m[pos].name);

        cout << "Enter new phone number: ";
        getline(cin, m[pos].phone);

        cout << "Member details updated successfully!\n";
    }

    void selectPlan()
    {
        int id, choice, months;
        double price;

        cout << "Enter member ID: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == id)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Member not found!\n";
            return;
        }

        cout << "\nChoose Membership Plan\n";
        cout << "1. Basic   - Rs. 1000/month\n";
        cout << "2. Standard - Rs. 1500/month\n";
        cout << "3. Premium - Rs. 2000/month\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            m[pos].plan = "Basic";
            price = 1000;
        }
        else if (choice == 2)
        {
            m[pos].plan = "Standard";
            price = 1500;
        }
        else if (choice == 3)
        {
            m[pos].plan = "Premium";
            price = 2000;
        }
        else
        {
            cout << "Invalid plan choice!\n";
            return;
        }

        cout << "Enter membership duration in months: ";
        cin >> months;

        if (months <= 0 || months > 120)
        {
            cout << "Enter a valid duration (1-120 months)!\n";
            return;
        }

        double amount = price * months;

        cout << "Membership cost: Rs. " << amount << endl;
        cout << "Pay now? (1 = Yes, 0 = No): ";
        int payChoice;
        cin >> payChoice;

        if (payChoice != 1)
        {
            cout << "Plan not activated. Payment pending.\n";
            return;
        }

        m[pos].months = months;
        m[pos].daysLeft = months * 30;
        m[pos].paid += amount;
        income += amount;

        cout << "Plan activated successfully!\n";
        cout << "Plan: " << m[pos].plan << endl;
        cout << "Validity: " << m[pos].daysLeft << " days\n";
        cout << "Payment received: Rs. " << amount << endl;
    }

    void renewMembership()
    {
        int id, months;

        cout << "Enter member ID: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == id)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Member not found!\n";
            return;
        }

        if (m[pos].plan == "Not selected")
        {
            cout << "Select a plan before renewal!\n";
            return;
        }

        double price;

        if (m[pos].plan == "Basic")
            price = 1000;
        else if (m[pos].plan == "Standard")
            price = 1500;
        else
            price = 2000;

        cout << "Enter extra months: ";
        cin >> months;

        if (months <= 0 || months > 120)
        {
            cout << "Invalid number of months!\n";
            return;
        }

        double amount = price * months;

        cout << "Renewal cost: Rs. " << amount << endl;
        cout << "Pay now? (1 = Yes, 0 = No): ";
        int payChoice;
        cin >> payChoice;

        if (payChoice != 1)
        {
            cout << "Renewal not completed. Payment pending.\n";
            return;
        }

        m[pos].months += months;
        m[pos].daysLeft += months * 30;
        m[pos].paid += amount;
        income += amount;

        cout << "Membership renewed successfully!\n";
        cout << "New validity: " << m[pos].daysLeft << " days\n";
    }

    void checkValidity()
    {
        int id;

        cout << "Enter member ID: ";
        cin >> id;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == id)
            {
                cout << "Member: " << m[i].name << endl;
                cout << "Plan: " << m[i].plan << endl;
                cout << "Days remaining: " << m[i].daysLeft << endl;

                if (m[i].daysLeft > 0)
                    cout << "Status: Active\n";
                else
                    cout << "Status: Expired or not activated\n";

                return;
            }
        }

        cout << "Member not found!\n";
    }

    void recordPayment()
    {
        int id;
        double amount;

        cout << "Enter member ID: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < total; i++)
        {
            if (m[i].id == id)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Member not found!\n";
            return;
        }

        cout << "Enter additional payment amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid payment amount!\n";
            return;
        }

        m[pos].paid += amount;
        income += amount;

        cout << "Payment recorded successfully!\n";
        cout << "Member's total recorded payments: Rs. "
             << m[pos].paid << endl;
    }

    void gymReport()
    {
        cout << "\n===== GYM REPORT =====\n";
        cout << "Total registered members: " << total << endl;
        cout << "Total payment recorded: Rs. " << income << endl;

        int active = 0, expired = 0;

        for (int i = 0; i < total; i++)
        {
            if (m[i].daysLeft > 0)
                active++;
            else
                expired++;
        }

        cout << "Active memberships: " << active << endl;
        cout << "Expired/unactivated memberships: "
             << expired << endl;
    }
};

int main()
{
    Gym g;
    int choice;

    do
    {
        cout << "\n====== GYM MANAGEMENT SYSTEM ======\n";
        cout << "1. Register Member\n";
        cout << "2. Display All Members\n";
        cout << "3. Update Member Details\n";
        cout << "4. Select Membership Plan\n";
        cout << "5. Renew Membership\n";
        cout << "6. Check Membership Validity\n";
        cout << "7. Record Additional Payment\n";
        cout << "8. Generate Gym Report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.registerMember();
            break;
        case 2:
            g.showMembers();
            break;
        case 3:
            g.updateMember();
            break;
        case 4:
            g.selectPlan();
            break;
        case 5:
            g.renewMembership();
            break;
        case 6:
            g.checkValidity();
            break;
        case 7:
            g.recordPayment();
            break;
        case 8:
            g.gymReport();
            break;
        case 0:
            cout << "Gym system closed successfully!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}