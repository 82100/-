#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<assert.h>

struct list
{
    char name[80];
    int price ;
};

typedef struct list lists ;

int main()
{
    int keep ;
    char output[128]={0};
    time_t t1 = time(NULL);
    struct tm *nPtr = localtime(&t1);
    int year = nPtr->tm_year + 1900;
    int month = nPtr->tm_mon + 1;
    int day = nPtr->tm_mday;
    FILE *fp;
    lists cost;
    do
    {
    fprintf( stdout , "\n是否輸入日期? < 1 > 是 .< 2 > 自動帶入  < 3 > 否 : " );
    fscanf( stdin , "%d" , &keep );
    
    if( keep ==1){
        fprintf( stdout , "請輸入年分 : " );
        fscanf( stdin , "%d" , &year );
        
        fprintf( stdout , "\n請輸入月分 : " );
        fscanf( stdin , "%d" , &month );
        
        fprintf( stdout , "\n請輸入日期 : " );
        fscanf( stdin , "%d" , &day );
        
        fp = fopen("list.txt","a+");
        assert( fp != NULL );
        
        fprintf( fp , " %d . %d . %d \n" , year , month , day );
        fprintf( fp , " 項目 \t\t 金額 \n" );
        
        fclose(fp);
    }
        else if( keep ==2){
            
            fp = fopen("list.txt","a+");
            assert( fp != NULL );
            
            fprintf( fp , " %d . %d . %d \n" , year , month , day );
            
            fclose(fp);
        }
    }while ( (keep != 1) && (keep != 2) && (keep != 3) ) ;
    
    fprintf( stdout , "\n %d . %d . %d \n" , year , month , day );
    
    do
    {
        fprintf( stdout , "\n請輸入購買項目 : " );
        fscanf( stdin , "%s" , &(cost.name) );
        
        fprintf( stdout , "\n請輸入項目金額 : " );
        fscanf( stdin , "%d" , &(cost.price) );
        
        fp = fopen("list.txt","a+");
        assert( fp != NULL );
        
        fprintf( fp , " %s\t\t%d \n" , cost.name , cost.price );
        
        fclose(fp);
        fprintf( stdout , " 項目 \t\t 金額 \n" );
        fprintf( stdout , " %s\t\t%d  \n" , cost.name , cost.price);
        
        
        fprintf( stdout , "\n繼續輸入項目? < 1 > 是 .< 2 > 否 : " );
        fscanf( stdin , "%d" , &keep );
        
    }while(keep==1);
    
    fprintf( stdout , "\n繼續觀看項目? < 1 > 是 .< 2 > 否 : " );
    fscanf( stdin , "%d" , &keep );
    
    if( keep == 1 ){
        fp = fopen("list.txt","r");
        assert( fp != NULL );
        
        while(fgets(output, 128, fp) != NULL)
            fputs( output , stdout );
        
        fclose(fp);		
    }
    system("pause");
    return 0 ;
}