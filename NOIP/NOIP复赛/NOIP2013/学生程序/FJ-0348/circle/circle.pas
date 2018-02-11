program circle;
var
a:array[0..1000000] of longint;
n,m,k,l,p,i,x:longint;

 procedure search(l:longint);
begin
		  if m+x<n then
			  a[x]:=a[m+x];
		  if m+x=n then
			  a[x]:=0;
		  if m+x>n then 
			  a[x]:=a[m+x-n];
		  end; 
		  
		  

    begin    
	
		  assign(input, 'circle.in');
		  reset(input);
		  assign(output,'circle.out');
		  rewrite(output);
       read(n,m,k,x);
       write(a[x]);
		  close(input);
		  close(output);
 		  p:=1;
		  for i:=1 to k do 
			 p:=p*10;
		  for i:= 1 to p do 		
		  search(l);
			end. 
	
		  
		  
		 
