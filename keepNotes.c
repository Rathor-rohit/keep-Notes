#include<conio.h>
#include<stdio.h>
//#include<time.h>
struct note
{
	char title[20];
	char notes[100];
}s1,s2;

int choice;
void addnote(void);
void viewnote(void);
int main()
{ start:   
  printf("------------------------------------------------------------------------------------------------------------------");
  printf("\n          ------------------------------------ NOTE KEEPER -----------------------------------");
  printf("\n------------------------------------------------------------------------------------------------------------------\n");
  printf("1.Add Note\n");
  printf("2.See Notes\n");
  printf("0.Exit\n");
  printf("Enter Your Choice : ");
  scanf("%d",&choice);
switch(choice)
{
	case 1:
		addnote();
		break;
	case 2:
	    viewnote();
		break;
	case 0:
	    exit(0);
		break;		
	default:
	    printf("\n Invalid Choice :");
		goto start;
			
}
	return 0;
	getch();
}
void addnote(void)
{
	printf("\n\t\tEnter Note Title : ");
	fflush(stdin);
	gets(s1.title);
	printf("\nEnter Note's Discription : ");
	fflush(stdin);
	gets(s1.notes);
	FILE *ptr;
	ptr=fopen("KeepNotes.bin","ab+");
    if(ptr==NULL)
    {
    	printf("Unable to save the note :: error -> due to file opening ");
	}
	else
	{
	fwrite(&s1,sizeof(s1),1,ptr);
	fclose(ptr);
	printf("\n\t\t******************* Note has been saved successfully **************");
    }	
	getch();
}
void viewnote(void)
{    int i;
    FILE *ptr;
	ptr=fopen("KeepNotes.bin","rb");
    if(ptr==NULL)
    {
    	printf("Unable to See the note :: error -> due to file opening ");
	}
	else
	{
    fseek(ptr,0,SEEK_SET);
	while(fread(&s1,sizeof(s1),1,ptr)==1)
	{
	printf("\n--------------------------------------------------------------------------\n");
    printf("\t              Note Title -->> %s",s1.title);
	printf("\n\t  Note's Discription   --->>%s",s1.notes);
	printf("\n--------------------------------------------------------------------------\n");
	i=1;
	}
	if(i=0)
	{
		printf("\t********************** No Notes found *********************");
	}
}
getch();
}


