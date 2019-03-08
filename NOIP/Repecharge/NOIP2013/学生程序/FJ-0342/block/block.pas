program day21;

var x:boolean;
	 n,t,m,i,j:longint;
      h,a:array [1..100000] of longint;
	  procedure maxvalue;
	  var i:longint;
	   begin
	     for i:= 1 to n do
			begin
		 if m< h[i] then m:= h[i];
			end;
	  end;
		  procedure search(p:longint);

		 begin
		 
		   repeat
	
					if j>h[p] then  begin inc(p) ;search(p);end
						else begin t:=t+1; i:=p;break;end;
							break;
	
			until p>n;
		end;
	 begin
		  assign(input,'block.in');
		  reset(input);
		  assign(output,'block.out');
	 	  rewrite(output);
		 readln(n);
	     for i:=1 to n do begin read(h[i]);a[i]:=0;end;
		 m:=0;
		 maxvalue;
		 t:=0;
		 for j := 1 to m do
		begin	
		 i:=1;
		x:=true;
		      repeat
                
				 if a[i]<h[i] then  begin a[i]:=a[i]+1;i:=i+1;end
					 else begin x:=false;t:=t+1;search(i);end;
					 
				until i>n;
					 	if   x then t:=t+1;
		end;	
		 writeln(t);
		  close(input);		
	 	  close(output);	
	 end.

