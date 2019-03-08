const
    city=10000;
var a ,visit :array[1..city,1..city] of longint;
       n,m,x,z,y,i,p,lim,max,j,t:longint;
	procedure weight (f,t:longint);
		var w:longint;
			begin
	          if (max<a[f,t] )and (lim > max )then max:=a[f,t];
			  visit[f,t]:=0;visit[t,f]:=0;
			  for w:=1 to m do
				  begin
			        while (a[f,w]>-1)and (visit [f,m]<0 )and (f<>w )do
					begin
						if lim>a[f,w] then
						begin	
						lim:=a[f,w];
						visit[f,w]:=0;visit[w,f]:=0;
						weight(w,t);
						end;
					  visit[f,w]:=-1;visit[w,f]:=-1;
					if max>lim then max:=lim;	
					end;
				end;
				
			end;
	 begin
                        assign(input,'truck.in');
			reset(input);
			assign(output,'truck.out');
			rewrite(output);
			readln(n,m);

                        	for i:=1 to m do
					begin
                                        for j:=1 to m do
                                        a[i,j]:=-1;
                                        end;
			for i:=1 to m do
				begin
			     readln(x,y,z);
			    if a[x,y]<z then begin a[x,y]:=z;a[y,x]:=z;end;
				end;
			readln(p);
				for i:=1 to p do
					begin
                                	for t:=1 to m do
                                        for j:=1 to m do
                                        visit[t,j]:=-1;
                                        readln(x,y);
				            max:=-1;
				            lim:=100000;

				           weight(x,y);
				writeln (max);
				end;
			close(input);
			close(output);
		end.
