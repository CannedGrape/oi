program truck;
var weight:array[-10..4000,-10..4000]of longint;
       n,m,q,i,j,k,err,x,y,z,min:longint;
	   
begin
     assign(input,'truck.in');reset(input);
	 assign(output,'truck.out');rewrite(output);
     fillchar(weight,sizeof(weight),100);
	 err:=weight[1,1];
	 readln(n,m);
	 for i:=1 to m do
		 begin
		     readln(x,y,z);
	         if (weight[x,y]=err) or (z>weight[x,y]) then weight[x,y]:=z;
	         if (weight[y,x]=err) or (z>weight[y,x]) then weight[y,x]:=z;
	     end;
	 for k:=1 to n do
		 for i:=1 to n do
			 for j:=1 to n do
				 if (weight[i,k]=err) or (weight[k,j]=err) then continue
					 else begin
						      if (weight[i,k]<weight[k,j]) then min:=weight[i,k]
								  else min:=weight[k,j];
							   if (min>weight[i,j]) or (weight[i,j]=err) then weight[i,j]:=min;
			              end;
	 readln(q);
	 for i:=1 to q do
		 begin
	         readln(x,y);
	         if (weight[x,y]=err) then writeln(-1)
				else writeln(weight[x,y]); 
	     end;
     close(input);
	 close(output);
end.