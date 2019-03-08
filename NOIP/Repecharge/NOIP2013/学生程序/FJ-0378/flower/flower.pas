program flower;
var f:array[-10..100010,0..1]of longint;
      i,j,k,n,ans:longint;
	  h:array[-10..100010]of longint;
	  

begin
     assign(input,'flower.in');reset(input);
	 assign(output,'flower.out');rewrite(output);
	 readln(n);
	 for i:=1 to n do
		 read(h[i]);
	 fillchar(f,sizeof(f),0);
	 f[1,0]:=1;
	 f[1,1]:=1;
	 for i:=2 to n do
		 begin
		    for j:=(i-1) downto 1 do
		    	 begin
		           if (h[j]<h[i]) and (f[j,0]>f[i,1]) then f[i,1]:=f[j,0];
		           if (h[j]>h[i]) and (f[j,1]>f[i,0]) then f[i,0]:=f[j,1];
               end;
			 inc(f[i,0]);inc(f[i,1]);
		 end;
	 ans:=0;
	 for i:=1 to n do
		 begin
	         if f[i,1]>ans then ans:=f[i,1];
			 if f[i,0]>ans then ans:=f[i,0];
	     end;
	 writeln(ans);
	 close(input);
	 close(output);
end.