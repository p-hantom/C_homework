#include <stdio.h> 
#include <string.h>
#include<stdlib.h>

#define LEN 80 
#define M 10
#define USECASES 100
typedef struct Priv{
	char category[LEN];
	int level;
}PRIV;

typedef struct Role{
	char name[LEN];
	int nPrivs;
	PRIV privs[M];
}ROLE;

typedef struct User{
	char name[LEN];
	int nRoles;
	char roleNames[M][LEN];
}USER;

PRIV makePRIV(char *category,int level){
	PRIV p;
	strcpy(p.category,category);
	p.level=level;
	return p;
}
PRIV makeP(char *str){
	PRIV priv; 
	char *s;
	int n;
	if(strstr(str,":")){
		s=strtok(str,":");
		strcpy(str,s);			
		s=strtok(NULL,":");
		n=*s-'0'; 			
	}
	else{
		n=-1;
	}	
	//printf("str=%s n=%d\n",str,n);
	priv = makePRIV(str,n);
	return priv;
}
ROLE makeROLE(char *name,int nPrivs,PRIV *privs) {
	ROLE r;
	strcpy(r.name,name);
	r.nPrivs=nPrivs;
	int i;
	for(i=0;i<nPrivs;i++){
		r.privs[i]=privs[i];
	}
	return r;
}

int getMaxLevel(char * category,PRIV priv[],int nPrivs) {
	int i,result = -1;
	for(i=0;i<nPrivs;i++){
		if(strcmp(category,priv[i].category)==0 ){
			result = priv[i].level;
			break;
		}
	}	
	return result;
}
void f(int develop){
	FILE *fp;
	if(develop){
		fp=fopen("input.txt","r");
	}
	
	int n,i,j,k,t,q; 
	int nRoles;
 	int nPrivs;
	int nUsers;	 
	PRIV priv[USECASES];
	ROLE role[USECASES];
	USER user[USECASES];
	char str[LEN],*s;
	
	//读入权限 
	if(develop){
		fscanf(fp,"%d",&nPrivs); 
	}
	else{
		scanf("%d",&nPrivs); 
	}
	 
	for(i=0;i<nPrivs;i++){
		if(develop){
			fscanf(fp,"%s",str); 
		}
		else{
			scanf("%s",str); 
		}				
		priv[i]=makeP(str);
	}
	
	//读入角色 	 
	if(develop){
		fscanf(fp,"%d",&nRoles); 
	}
	else{
		scanf("%d",&nRoles); 
	}
	char str3[LEN] ;	
	for(i=0;i<nRoles;i++){
		if(develop){			
			fscanf(fp,"%s",role[i].name); 
			fscanf(fp,"%d",&role[i].nPrivs);
		}
		else{
			scanf("%s",role[i].name); 
			scanf("%d",&role[i].nPrivs);
		}
		 			
		for(j=0;j<role[i].nPrivs;j++){
			if(develop){			
				fscanf(fp,"%s",str3); 				
			}
			else{
				scanf("%s",str3);
			}
			
			role[i].privs[j]=makeP(str3); 			
		}		
	}
	
	//读入用户 
	char str2[LEN] ;	
	if(develop){
		fscanf(fp,"%d",&nUsers); 
	}
	else{
		scanf("%d",&nUsers); 
	}	
	for(i=0;i<nUsers;i++){	
		if(develop){
			fscanf(fp,"%s",user[i].name);  
			fscanf(fp,"%d",&user[i].nRoles);  
		}
		else{
			scanf("%s",user[i].name);  
			scanf("%d",&user[i].nRoles); 
		}	
		 				
		for(j=0;j<user[i].nRoles;j++){	
			if(develop){
				fscanf(fp,"%s",user[i].roleNames[j]);
			}
			else{
				scanf("%s",user[i].roleNames[j]);
			}					
		}
	}
	
	// 读入查询项： 
	if(develop){
		fscanf(fp,"%d",&n); 
	}
	else{
		scanf("%d",&n); 
	} 
	char name[LEN];
	char cat[LEN];
	int level;
	for(q=0;q<n;q++){
		if(develop){
			fscanf(fp,"%s",name); 
		 	fscanf(fp,"%s",str);  
		}
		else{
			scanf("%s",name); 
		 	scanf("%s",str); 
		}
		 
		 if(strstr(str,":")){
			s=strtok(str,":");
			strcpy(cat,s);			
			s=strtok(NULL,":");
			level=*s-'0'; 			
		}
		else{
			strcpy(cat,str);	
			level=-1;
		}
	 
	 //查找用户 
	 int nameFound=0;	 	 
	 for(i=0;i<nUsers;i++){
	 	if(strcmp(name,user[i].name)==0){
	 		nameFound=1;			 
	 		break;
	 	}
	 }
	 
	 if(!nameFound){
	 	printf("false\n");
	 	return;
	 }
 	 	 	 
	 int tmp,maxPrivLevel,rolePrivLevel=0,privFound=0;
	 for(j=0;j<user[i].nRoles;j++){ 	 	
	 		char *rname = user[i].roleNames[j];  		 		
	 		for(k=0;k<nRoles;k++){
	 			if(strcmp(rname,role[k].name)==0){
	 				for(t=0;t<role[k].nPrivs;t++){
	 					 if(strcmp(cat,role[k].privs[t].category) == 0){
	 					 	tmp=role[k].privs[t].level;
	 					 	privFound=1;
	 					 	break;
	 					 }
	 				}
	 				if(tmp>rolePrivLevel) {
						rolePrivLevel=tmp;
					}	 
	 			}
	 		}		 			 
	 	 } 
	 	 
	 	 if(privFound ){
	 	 	maxPrivLevel = getMaxLevel(cat,priv,nPrivs);
	 	 	if(level==-1) {
	 	 		if(maxPrivLevel==-1) {
	 	 			printf("true\n");
	 	 		}
	 	 		else{
	 	 			printf("%d\n",rolePrivLevel);
	 	 		} 		  	
	 		} 
	 		else{ 			
	 			if(level<=maxPrivLevel && level<=rolePrivLevel){
	 				printf("true\n");
	 			}
	 			else{
			 		printf("false\n");
			 	}
	 		} 
	 	}
	 	else{
	 		printf("false\n");
	 	} 
	 }
	 
	 if(develop){
		fclose(fp);
	}
}
int main(){  
	int develop = 1;
	f(1);
	
	return 0;
}

//
//void test(){
//	int n,i,j,k,t; 
//	char str[10];
//	
//	PRIV priv[]={{"crm",2},{"git",3},{"game",0}} ;	
// 	ROLE role[4]={
//	     {"hr",1,{"crm",2}},
//	     {"it",3,{"crm",1,"git",1,"game",0}},
//	     {"dev",2,{"git",3,"game",0}},
//	     {"qa",1,{"git",2}}
//	 }; 
//
//	 USER user[]={
//	 	{"alice",1,{"hr"}},
//	 	{"bob",2,{"it","qa"}},
//	 	{"charlie",1,{"dev"}}
//	 };
//	 
//	 char *name="charlie";
//	 char *cat="git";
//	 int level=3;
//	 int nameFound=0;	 
//	  
//	 for(i=0;i<sizeof(user)/sizeof(USER);i++){
//	 	if(strcmp(name,user[i].name)==0){
//	 		nameFound=1;			 
//	 		break;
//	 	}
//	 }
//	 
//	 if(!nameFound){
//	 	printf("false\n");
//	 	return 0;
//	 }
//	 	 
//	 int nRoles = sizeof(role)/sizeof(ROLE);
// 	 int nPrivs=sizeof(priv)/sizeof(PRIV);	 
//	 
//	 int tmp,maxPrivLevel,rolePrivLevel=0,privFound=0;
//	 for(j=0;j<user[i].nRoles;j++){ 	 	
// 		char *rname = user[i].roleNames[j];  		 		
// 		for(k=0;k<nRoles;k++){
// 			if(strcmp(rname,role[k].name)==0){
// 				for(t=0;t<role[k].nPrivs;t++){
// 					 if(strcmp(cat,role[k].privs[t].category) == 0){
// 					 	tmp=role[k].privs[t].level;
// 					 	privFound=1;
// 					 	break;
// 					 }
// 				}
// 				if(tmp>rolePrivLevel) {
//					rolePrivLevel=tmp;
//				}	 
// 			}
// 		}		 			 
// 	 } 
// 	 
// 	 if(privFound ){
// 	 	maxPrivLevel = getMaxLevel(cat,priv,nPrivs);
// 	 	if(level==-1) {
// 	 		if(maxPrivLevel==-1) {
// 	 			printf("true\n");
// 	 		}
// 	 		else{
// 	 			printf("%d\n",rolePrivLevel);
// 	 		} 		  	
// 		} 
// 		else{ 			
// 			if(level<=maxPrivLevel && level<=rolePrivLevel){
// 				printf("true\n");
// 			}
// 			else{
//		 		printf("false\n");
//		 	}
// 		} 
// 	}
// 	else{
// 		printf("false\n");
// 	} 
//}
