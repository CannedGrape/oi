program truck;
var
n,m,x,y,z,j,i,c,k:longint;
q:integer;
a,ans:array [1..10000,1..10000] of integer;

procedure solve(x,y:longint);
begin
  for j:=1 to n do
	  if a[x,j]<>0 then
		  begin
	        if a[j,y]<>0 then
				begin
			      if a[j,y]>a[x,j] then break
					  else begin
							 begin
					         if a[j,k]=0 then break
						        else if (a[j,k]<a[j,y])  then
									begin
					                 ans[j,k]:=-1
								    end	  else
									begin
								     if (ans[j,k]<a[j,k]) and (ans[j,k]<a[x,j]) then
								        if a[j,k]>a[x,j] then ans[j,k]:=a[x,j]  else ans[j,k]:=a[j,k];
									 solve(k,y);
							        end;
							end;
						end;
				end;
		   end;
end;







begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
 read(n,m);
 fillchar(a,sizeof(a),0);
 fillchar(ans,sizeof(ans),0);
 c:=0;
 for i:=1 to m do
	 begin
	   readln(x,y,z);
       a[x,y]:=z;
     end;
  readln(q);
  for i:= 1 to q do
	begin
		readln(x,y);
        solve(x,y);
        for j:=x to n do
			for k:=x to n do
				if c<ans[j,k] then c:=ans[j,k];
		writeln(c);
	 end;

close(input);
close(output);
end.
