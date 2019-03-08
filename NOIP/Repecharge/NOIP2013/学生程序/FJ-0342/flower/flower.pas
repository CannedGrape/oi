program day22;
 var g1,g2,h:array [1..100000]of longint;
       i,a,b,n,m:longint;
procedure search1;
	   var k:longint;
	   
	   begin 
	   k:=2;
	   for i:=2 to n do 
		 begin 
	   if ((k mod 2 )=0 )and (g1[i]>g1[k-1] )then
		   begin g1[k]:=g1[i];inc(k);end
    else
		if ((k mod 2 )<>0 )and (g1[i]<g1[k-1]) then 
			begin g1[k]:=g1[i];inc(k);end;
			end;	
	     a:=k;
	end;
			
procedure search2;
	   var k:longint;
	   
	   begin 
	       k:=2;
	     for i:=2 to n do 
		  begin 
				if ((k mod 2 )=0 )and (g2[i]<g2[k-1] )then begin g2[k]:=g2[i];inc(k);end
				else if ((k mod 2 )<>0 )and (g2[i]>g2[k-1] )then begin g2[k]:=g2[i];inc(k);end;
			end;	
	b:=k;
	end;
	begin   
	 assign(input,'flower.in');
		 reset(input);
		 assign(output,'flower.out');
	 	 rewrite(output);
		 readln(n);
		 for i:=1 to n do begin 
			 read(h[i]);
		     g1[i]:=h[i];
			 g2[i]:=h[i];
		 end;
		
		 search1;
		 search2;
        if a>b then m:=a else m:=b;
			writeln(m);
		 
		  close(input);		
	 	 close(output);	
	 end.