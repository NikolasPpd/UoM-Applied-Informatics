#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FILE1 "i4f6.txt"

#define HMax 9              /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
	char name[11];
	char surname[21];
	char number[11];
	int code;

} ListElementType;  //τύπος δεδομένων για τα στοιχεία της λίστας

typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);

void BuildHashList(HashListType *HList);
int findAverage(KeyType Key);
void Search_HashList_By_Subject(HashListType HList, int code);

int main()
{
	HashListType HList;
	char checker;
	ListElm temp;
	int Loc,Pred;
	int code;


    //1 - Build Hash List
    printf("1. Create HashList\n");
    CreateHashList(&HList);
    BuildHashList(&HList);
	PrintPinakes(HList);

    //2 - Insert New Teacher
    printf("2. Insert new teacher\n");
	do{
		printf("Enter teacher's name: ");
		scanf(" %s", temp.Data.name);
		printf("Enter teacher's surname: ");
		scanf(" %s", temp.Data.surname);
		printf("Enter teacher's phone: ");
		scanf(" %s", temp.Data.number);
		printf("Enter teacher code: ");
		scanf("%d",&temp.Data.code);
		temp.RecKey[0] = '\0';
        strcat(temp.RecKey, temp.Data.name);
        strcat(temp.RecKey, " ");
        strcat(temp.RecKey, temp.Data.surname);
		AddRec(&HList,temp);

		printf("\nContinue Y/N: ");
        scanf(" %c",&checker);
        while(tolower(checker)!='y' && tolower(checker)!='n'){
            printf("Invalid character. Try again: ");
            scanf(" %c",&checker);
        }
    } while(tolower(checker)=='y');
	PrintPinakes(HList);

    //3 - Delete a Teacher
	printf("3. Delete a teacher\n");
    printf("Enter teacher's name: ");
	scanf(" %s", temp.Data.name);
	printf("Enter teacher's surname: ");
	scanf(" %s", temp.Data.surname);
	temp.RecKey[0] = '\0';
    strcat(temp.RecKey, temp.Data.name);
    strcat(temp.RecKey, " ");
    strcat(temp.RecKey, temp.Data.surname);
    SearchHashList(HList, temp.RecKey,&Loc,&Pred);
    if(Loc==-1){
		printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n",temp.RecKey);
	}
	else{
		DeleteRec(&HList,temp.RecKey);
	}
	PrintPinakes(HList);

    //4 - Search for a Teacher
	printf("4. Search for a teacher\n");
	printf("Enter teacher's name: ");
	scanf(" %s", temp.Data.name);
	printf("Enter teacher's surname: ");
	scanf(" %s", temp.Data.surname);
	temp.RecKey[0] = '\0';
    strcat(temp.RecKey, temp.Data.name);
    strcat(temp.RecKey, " ");
    strcat(temp.RecKey, temp.Data.surname);
	SearchHashList(HList, temp.RecKey,&Loc,&Pred);
	if(Loc==-1){
		printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n\n",temp.RecKey);
	}
	else{
		printf("[%s %s, %s, %d]\n\n", HList.List[Loc].Data.name, HList.List[Loc].Data.surname, HList.List[Loc].Data.number, HList.List[Loc].Data.code);
	}

    //5 - Search by Subject
	printf("5. Search by subject\n");
	printf("Enter code: ");
	scanf("%d", &code);
	printf("List of teachers with subject code %d:\n", code);
	Search_HashList_By_Subject(HList, code);

    return 0;
}

int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
    return findAverage(Key)%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}

void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d, ", HList.HashTable[i]);
    printf("\n");
	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s %s, %d\n", i, HList.List[i].Data.name, HList.List[i].Data.surname, HList.List[i].Link);
	printf("\n");
}

void BuildHashList(HashListType *HList)
{
	FILE *f1;
    int nscan;
	char termch;
	ListElm temp;
    f1=fopen(FILE1,"r");

    while(TRUE){
        nscan = fscanf(f1, "%11[^,],%21[^,],%11[^,],%d%c", temp.Data.name, temp.Data.surname, temp.Data.number, &temp.Data.code, &termch);
        if(nscan == EOF){
            break;
        }
        strcat(temp.RecKey, temp.Data.name);
        strcat(temp.RecKey, " ");
        strcat(temp.RecKey, temp.Data.surname);
		AddRec(HList,temp);
		temp.RecKey[0] = '\0';

    }

    fclose(f1);
}

int findAverage(KeyType Key)
{
    int tempFirst, tempLast;

    tempFirst = toupper(Key[0]) - 64;
    tempLast = toupper(Key[strlen(Key)-1]) - 64;

    return (tempFirst + tempLast) / 2;
}

void Search_HashList_By_Subject(HashListType HList, int code)
{
	int i, SubIndex;

    for (i=0; i<HMax;i++)
    {
		SubIndex = HList.HashTable[i];

    	while ( SubIndex != EndOfList )
        {
			if(HList.List[SubIndex].Data.code==code){
               	printf("%d: [%s %s, %s, %d]\n",SubIndex, HList.List[SubIndex].Data.name,HList.List[SubIndex].Data.surname,HList.List[SubIndex].Data.number,HList.List[SubIndex].Data.code);
			}
			SubIndex = HList.List[SubIndex].Link;
        }
    }
}
