#include <iostream>
using namespace std;
struct resource
{
	int rid;
	int amount;
	resource *next=NULL;
};
resource *rlist=NULL, *freelist=NULL,*tempresourcelist=NULL,*totallist=NULL, *finishedlist = NULL;
struct process {
	int pid;
	resource *maxlist=NULL;
	resource *allocatedlist=NULL;
	resource *needlist=NULL;
	
	process *next=NULL;
	
};
process *plist=NULL;
int x,y;
void safechecker(int x);
void initialize();
void addlasttoresourcelist(resource *t)
{	
	resource *temp,*temp1;
	temp=tempresourcelist;
	if(temp==NULL)
		tempresourcelist=t;
	else{
		temp1=tempresourcelist;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=t;
		//cout<<endl<<t->amount<<endl;
		
		
	}
	
}

void addlastprocess(process *temp)
{
	process *temp1;
	temp1=plist;
	if(plist==NULL)
		plist=temp;
	else{
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		
	}
	
	
}
void calculateneed();

int main()
{
	process *temp;
	resource *tempres;
	initialize();
	calculateneed();
	safechecker(x);
	temp=plist;
	
	cout<<"\nMax list\t\t"<<"Allocated list \t\t"<<"Need list";
	while(temp!=NULL)
	{
		cout<<endl;
		tempres=temp->maxlist;
		while(tempres!=NULL){
			cout<<tempres->amount<<" ";
			tempres=tempres->next;
		}
		tempres=temp->allocatedlist;
		cout<<"\t\t";
		while(tempres!=NULL){
			cout<<tempres->amount<<" ";
			tempres=tempres->next;
		}
		//need output
		tempres=temp->needlist;
		cout<<"\t\t";
		while(tempres!=NULL){
			cout<<tempres->amount<<" ";
			tempres=tempres->next;
		}
		
		//cout<<endl;
		temp=temp->next;
	}
	return 0;
	
}


void calculateneed(){
	process *temp;
	resource *tempr;
	resource *maxptr;
	resource *allocateptr;
	temp = plist;
	while(temp != NULL){
		maxptr= temp->maxlist;
		allocateptr=temp->allocatedlist;
		while(maxptr!=NULL){
			tempr = new resource;
			tempr->next=NULL;
			tempr->amount= maxptr->amount - allocateptr->amount;
			addlasttoresourcelist(tempr);
			maxptr=maxptr->next;
			allocateptr=allocateptr->next;
		}
		temp->needlist=tempresourcelist;
		tempresourcelist=NULL;
		temp= temp->next;
	}
}




void initialize()
{
	int n,m;
	process *temp;
	resource *tempr,*totalinstance, *currentallocatedresource;
	cout<<"\nEnter the total number of processes---";
	cin>>n;
	cout<<"\nAnd now enter the total number of resource types--";
	cin>>m;
	x=m;
	y=n;
	for(int j=1;j<=m;j++)
	{
		tempr=new resource;
		tempr-> next=NULL;
		cout<<"\nEnter total number of instances for resource type: "<<j<<": ";
		cin>>tempr->amount;
		addlasttoresourcelist(tempr);
	}// end loop j
	cout<<"\nfiniiiished";
	totallist=tempresourcelist;
	tempresourcelist=NULL;
	
	cout<<"\n\n\nEnter the max list for all processes: "<<endl;
	for(int i=1;i<=n;i++)
	{
		totalinstance=totallist;
		cout<<"\nMax list for process "<<i<<": ";
		temp=new process;
		temp->pid=i;
		temp->next=NULL;
		for(int k=1;k<=m;k++) 
		{
			cout<<"\n\tFor resource type "<<k<<": ";
			tempr=new resource;
			tempr->rid=k;
			tempr->next=NULL;
			max:cin>>tempr->amount;			
			if(tempr->amount>totalinstance->amount)
			{
				cout<<"\nThere is no such resource. Please enter a number <= "<<totalinstance->amount;
				goto max;
				
			}//end if 
			addlasttoresourcelist(tempr);
			totalinstance=totalinstance->next; 
		}//end loop k
		temp->maxlist=tempresourcelist;
		tempresourcelist=NULL;
		addlastprocess(temp);
	}//end loop i
	
	cout<<"\n\n\n\t Now enter the allocated list for each process\n";
	temp=NULL;
	temp=plist;
	for(int i=1;i<=n;i++)
	{
		currentallocatedresource=temp->maxlist;
		cout<<"\nEnter allocated list for process "<<i<<": ";
		
		for(int k=1;k<=m;k++)
		{
			tempr=new resource;
			tempr->next=NULL;
			tempr->rid=k;
			cout<<"\n\tresource type "<<k<<": ";
			allcted:cin>>tempr->amount;
			if(tempr->amount>currentallocatedresource->amount)
				goto allcted;			
			addlasttoresourcelist(tempr);
			currentallocatedresource=currentallocatedresource->next; 
		}
		temp->allocatedlist=tempresourcelist;
		tempresourcelist=NULL;
		temp=temp->next;
		
	}
}
