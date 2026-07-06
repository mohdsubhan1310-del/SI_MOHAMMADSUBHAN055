#include <stdio.h>
int main()
{
    int id[15] = {11,12,13,14,21,22,23,24,31,32,33,41,42,43,44};
    char item[15][50] = {
        "Milk","Butter","Paneer","Maggi",
        "Jeans","T-Shirt","Track pants","Shirt",
        "Iron","Mixer","Cooker",
        "Notebook","Pens","Sketch pens","Calculator"
    };
    char category[15][20] = {
        "Grocery","Grocery","Grocery","Grocery",
        "Clothes","Clothes","Clothes","Clothes",
        "Appliances","Appliances","Appliances",
        "Stationary","Stationary","Stationary","Stationary"
    };
    float mrp[15] = {60,55,90,70,2499,999,1999,1799,1499,3499,2999,120,80,150,450};
    int offer[15] = {5,10,8,15,18,22,10,5,10,12,15,5,8,10,12};
    int stock[15] = {100,80,50,120,20,25,15,18,10,8,12,60,70,40,25};
    int choice, pid, qty, i, found;
    float amount, bill = 0;
    
     printf("\n\n");
     printf("``````````````````````````````````````````````````````````````\n");
     printf("`                WELCOME TO DMART STORE                      `\n");
     printf("``````````````````````````````````````````````````````````````\n");

    do
    {
        printf("* 1. View Inventory                                          *\n");
        printf("* 2. Purchase Item                                           *\n");
        printf("* 3. Checkout & Exit                                         *\n");
        printf("``````````````````````````````````````````````````````````````\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("\n--------------------------------------------------------------------------------");
            printf("\n%-5s %-18s %-15s %-10s %-10s %-10s",
           "ID", "ITEM", "CATEGORY", "MRP", "OFFER", "STOCK");
            printf("\n--------------------------------------------------------------------------------");
            for(i = 0; i < 15; i++)
                    {
                        printf("\n%-5d %-18s %-15s %-10.2f %-8d%% %-d",
                        id[i],
                        item[i],
                        category[i],
                        mrp[i],
                        offer[i],
                        stock[i]);
                    }
            printf("\n--------------------------------------------------------------------------------\n");
            break;
    
            case 2:
                printf("\nEnter Item ID : ");
                scanf("%d", &pid);
                found = 0;
                for(i = 0; i < 15; i++)
                {
                    if(id[i] == pid)
                    {
                        found = 1;
                        printf("\n-----------------------------------");
                        printf("\nItem Name : %s", item[i]);
                        printf("\nCategory  : %s", category[i]);
                        printf("\nMRP       : %.2f", mrp[i]);
                        printf("\nDiscount  : %d%%", offer[i]);
                        printf("\nAvailable : %d", stock[i]);
                        printf("\n-----------------------------------");
                        printf("\nEnter Quantity : ");
                        scanf("%d", &qty);
                        if(qty <= 0)
                        {
                            printf("\nINVALID QUANTITY!\n");
                        }
                        else if(qty <= stock[i])
                        {
                            amount = qty * mrp[i];
                            amount = amount - (amount * offer[i] / 100.0);
                            stock[i] -= qty;
                            bill += amount;
                            printf("\n-----------------------------------");
                            printf("\nPurchase Successful!");
                            printf("\nAmount Payable : %.2f", amount);
                            printf("\nCurrent Bill   : %.2f", bill);
                            printf("\n-----------------------------------\n");
                        }
                        else
                        {
                            printf("\nINSUFFICIENT STOCK!\n");
                        }
                        break;
                    }
                }
                if(found == 0)
                {
                    printf("\nINVALID ITEM ID!\n");
                }
                break;

            case 3:
            {
                float gst = bill * 0.05;
                float grandtotal = bill + gst;
                printf("\n\n");
                printf("--------------------------------------------------------------\n");
                printf("                      DMART FINAL BILL                        \n");
                printf("--------------------------------------------------------------\n");
                printf("Subtotal          : %.2f\n", bill);
                printf("GST (5%%)          : %.2f\n", gst);
                printf("==============================================================\n");
                printf("Grand Total       : %.2f\n", grandtotal);
                printf("--------------------------------------------------------------\n");
                printf("        THANK YOU FOR SHOPPING WITH US!                       \n");
                printf("                  VISIT AGAIN :)                              \n");
                printf("--------------------------------------------------------------\n");
                break;
            }

            default:
                printf("\n``````````````````````````````````````````````\n");
                printf(" INVALID CHOICE!\n");
                printf(" Please Enter Only 1, 2 or 3.\n");
                printf("``````````````````````````````````````````````\n");
        }
    } 
    while(choice != 3);
    return 0;
}
