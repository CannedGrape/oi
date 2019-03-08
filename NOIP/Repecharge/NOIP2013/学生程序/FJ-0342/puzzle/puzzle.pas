program aday23;
  var qi,e:array [1..500,1..500]of integer;
     i,m,n,q,j,a,b,x,y:integer;
	 procedure play;
	       var ans:longint;
		   begin 
		   ans:=-1;
		   if (m=a )and (n=b) then ans :=0;
			   if (x=a) and (y=b)  then 
				   if ((m=a )and (abs(n-b)=1) )or ((n=b )and (abs(m-a)=1)) then ans:=1;
		   writeln(ans);
		   end;
	 begin
	    assign(input,'puzzle.in');
		 reset(input);
		 assign(output,'puzzle.out');
	 	 rewrite(output);
		 readln(n,m,q);
		 for i:=1 to n do 
			 for j:=1 to m do 
				 begin  
					if j=m then readln(qi[i,j])
						else read (qi[i,j]);
				end;
		for i:= 1 to q do 
         begin
                readln(x,y,m,n,a,b);
			    e[x,y]:=3;e[m,n]:=4;e[a,b]:=5;//空白格为3，初始位为4，目标位为5//
			play;
		end;
		close(input);		
	 	 close(output);
	end.	