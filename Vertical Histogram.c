/*Vertical Histogram based on student's grades*/
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<math.h>

void read(int[],int);
float mesos(int [],int);
float deviation(int [],int);
void ekato(int [],int);
void print(int [],int,char []);
/*Main*/
int main (){
	int vathmoi[100],mathites,i;
	char name[100];
	printf("Number of Students: ");
    scanf("%d",&mathites);
    printf("Subject: ");
    scanf("%s",&name);
	read(vathmoi,mathites);
	print(vathmoi,mathites,name);
	printf("\n______________________________\n");
	printf("\nGrades Average: %.2f\n",mesos(vathmoi,mathites));   
	printf("Standard Deviation: %.2f\n",deviation(vathmoi,mathites));
	printf("______________________________\n\n");
	printf("                                             [%s]\n\n\n\n",name);
	ekato(vathmoi,mathites);
	return 0;
}

/*This function reads the scores for each student and checks if the score is belw 10 or above 100*/
void read(int vathmoi[100],int mathites){  
	int i;
	printf("Scores:\n");
	for(i=0;i<mathites;i++){
		scanf("%d",&vathmoi[i]);
		while(vathmoi[i]<0 || vathmoi[i]>100){   
			printf("Wrong Input.Please enter the score again: ");
			scanf("%d",&vathmoi[i]);			
		}
	}
}
/*This function finds the avarage of the scores*/
float mesos(int vathmoi[100],int mathites){
	int i,sum=0;
	for(i=0;i<mathites;i++){
		sum+=vathmoi[i];
	}
	return (float)sum/mathites;
}

//This function caclulates the Standard Deviation
float deviation(int vathmoi[100],int mathites){
	int i;
	float d=0;
	for(i=0;i<mathites;i++){
		/*Formula to find the Standard Deviation*/
		d+=pow(((vathmoi[i])-mesos(vathmoi,mathites)),2);
	}	
	return (float)sqrt(d/mathites);
}
/* Prints the Array of Scores*/
void print(int vathmoi [100],int mathites ,char name[100]){
	int i=0;
	printf("______________________________\n");
	printf("\n%d Scores in %s\n",mathites,name);
	printf("______________________________\n\n");
	for(i=0;i<mathites;i++){
		printf("%d  ",vathmoi[i]);
		if(i%10==0){
			printf("\n"); 
		}
	}	
}

/*This function prints the histogram based on student's grades*/
void ekato(int vathmoi[100],int mathites){
	int i=0,cnt[10]={0},percentages[10],j=0;
	for(i=0;i<mathites;i++){
		if(vathmoi[i]<10){
			cnt[0]++;
		}
		else if(vathmoi[i]>=10 && vathmoi[i]<=19){
			cnt[1]++;
		}
		else if(vathmoi[i]>=20 && vathmoi[i]<=29){
			cnt[2]++;
		}
		else if(vathmoi[i]>=30 && vathmoi[i]<=39){
			cnt[3]++;
		}
		else if(vathmoi[i]>=40 && vathmoi[i]<=49){
			cnt[4]++;
		}
		else if(vathmoi[i]>=50 && vathmoi[i]<=59){
			cnt[5]++;
		}
		else if(vathmoi[i]>=60 && vathmoi[i]<=69){
			cnt[6]++;
		}
		else if(vathmoi[i]>=70 && vathmoi[i]<=79){
			cnt[7]++;
		}
		else if(vathmoi[i]>=80 && vathmoi[i]<=89){
			cnt[8]++;
		}
		else if(vathmoi[i]>=90){
			cnt[9]++;
		}	
	}
	/*Finds the percentage for each spectrum*/
	for(i=0;i<10;i++){
		percentages[i]=(cnt[i]*100)/mathites;
	}
	
	int mx=percentages[0];
	
	/*Prints the graph*/
    for(i=0;i<=9;i++){
    	if(percentages[i]>mx){
    		mx=percentages[i];
		}      
	}
	
    for(i=mx;i>=1;i--){
        for(j=0;j<=9;j++){
            if(percentages[j]>=i)
                printf("    %c    ",219); /*219 is a symbol from the ASCII table*/
            else
                printf("         ");
        }   
        printf("\n");
    
	}
	  printf("   0-9     10-19    20-29    30-39    40-49    50-59    60-69    70-79    80-89    90-100");
}
