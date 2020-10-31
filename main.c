#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
    int id;
    int quantity;
    char name [30];
};
struct data books[10];
int count_line = 0;

void add_book()
{
    int x , y;
    char z[30];
    FILE *add;
    add = fopen("mybook.txt","a+");
    printf("please enter book id\n");
    scanf("%d",&x);
    printf("please enter the quantity of book\n");
    scanf("%d",&y);
    printf("please enter book name\n");
    getchar();
    gets(z);
    fprintf(add,"%d\t%d\t%s\n",x,y,z);
    fclose(add);
}
void delete_book()
{
    FILE *fp1;
    int delete_id;
    printf("Please Enter the id book u want to delete :\n");
    scanf("%d",&delete_id);
    fp1=fopen("mybook.txt","w");
    for(int j=0;j < count_line;j++)
    {
        if(books[j].id == delete_id)
        {
            continue;
        }
        else
            fprintf(fp1,"%d\t%d\t%s\n",books[j].id,books[j].quantity,books[j].name);
    }
    fclose(fp1);
}

int search_id(const struct data books[],int line ,int id , int low)
{
    if(low<line && books[low].id==id)
    {
        printf("ID\tQuantity\tName\n");
        printf("%d\t%d\t%s\n",books[low].id,books[low].quantity,books[low].name);
        return 1;
    }
    else if (low >= line)
        return 0;
    else
         search_id(books,line,id,low+1);

}

int search_name(struct data books[],char name2[],int low,int high)
{
int temp=0;
    char z[30];
    for(int i=1;i<count_line;i++)
    {
        for(int j=0;j<count_line-i;j++)
        {
            if(strcmp(books[j].name,books[j+1].name)>0)
            {
                //swap id
                temp=books[j].id;
                books[j].id=books[j+1].id;
                books[j+1].id=temp;
                // swap quantity
                temp=books[j].quantity;
                books[j].quantity=books[j+1].quantity;
                books[j+1].quantity=temp;
                //swap name
                strcpy(z,books[j].name);
                strcpy(books[j].name,books[j+1].name);
                strcpy(books[j+1].name,z);
            }
        }
    }
   int middle;
   while (low <= high)
   {
       middle=(low+high)/2;
       if(strcmp(name2,books[middle].name)==0)
       {
           printf("ID\tQuantity\tName\n");
           printf("%d\t%d\t%s\n",books[middle].id,books[middle].quantity,books[middle].name);
           return 1;
       }
       else if (strcmp(name2,books[middle].name) <= -1)
       {
           high = middle - 1;
       }
       else if (strcmp(name2,books[middle].name) == 1)
       {
           low = middle + 1;
       }
   }
   return 0;
}






void sorted_name()
{

    int temp=0;
    char s[30];
    for(int i=1;i<count_line;i++)
    {
        for(int j=0;j<count_line-i;j++)
        {
            if(strcmp(books[j].name,books[j+1].name)>0)
            {
                //swap id
                temp=books[j].id;
                books[j].id=books[j+1].id;
                books[j+1].id=temp;
                // swap quantity
                temp=books[j].quantity;
                books[j].quantity=books[j+1].quantity;
                books[j+1].quantity=temp;
                //swap name
                strcpy(s,books[j].name);
                strcpy(books[j].name,books[j+1].name);
                strcpy(books[j+1].name,s);
            }

        }
    }

    printf("ID\tQuantity\tName\n");
    for(int x=0;x<count_line;x++)
    {
        printf("%d\t%d\t%s\n",books[x].id,books[x].quantity,books[x].name);
    }
}

void unsorted()
{
    printf("ID\tQuantity\tName");
    for(int j=0;j<count_line;j++)
    {
        printf("\n%d\t%d\t%s\n",books[j].id,books[j].quantity,books[j].name);
    }
}
int main()
{
    char ch,ask;
    int menuno,i=0;
    FILE *pl;
    pl=fopen("mybook.txt","r");
    ch=getc(pl);
    while(ch!=EOF)
    {
        if (ch=='n')
        {
            count_line+=1;
        }
        ch = getc(pl);
    }
    fclose(pl);
    FILE *store;
    store = fopen("mybook.txt","r");
    while(!feof(store) && i < count_line )
   {
       fscanf(store,"%d %d %[^\n]s\n",&books[i].id,&books[i].quantity,books[i].name);
       i++;
   }
    fclose(store);
    FILE *found;
    if((found=fopen("mybook.txt","r"))==NULL)
        printf("File not found \n");
    else
    {
    for(int i=0;i<10;i++)
    {
        printf("1-Insert a book\n");
        printf("2-Delete a book by id\n");
        printf("3-Search a book by id\n");
        printf("4-Search a book by name\n");
        printf("5-Display all books sorted by name\n");
        printf("6-Display all books unsorted\n");
        scanf("%d",&menuno);
        switch(menuno)
        {
        case 1:
            add_book();
            break;
        case 2:
            delete_book();
            break;
        case 3:
            {
            int id_no,start=0,y;
            printf("Enter id to search \n");
            scanf("%d",&id_no);
            y=search_id(books,count_line,id_no,start);// book-->array ,count_line-->number of line in file,start-->index 0
            if(y!=1)
                printf("Not found \n");
            break;
            }

        case 4:
            {
            int c;
            char name1[30];
            printf("Enter the name to be searched\n");
            getchar();
            gets(name1);
            c = search_name(books,name1,0,count_line-1);
            if (c==0)
            {
                printf("Not Found\n");
            }
            break;
        }
        case 5:
            sorted_name();
            break;
        case 6:
            unsorted();
            break;
        }
        printf("Do u wants to perform any additional operation (y,n)\n");
        scanf("%s",&ask);
        if(ask == 'y')
            continue;
        else if (ask == 'n')
            break;
    }
    }

    return 0;
}
