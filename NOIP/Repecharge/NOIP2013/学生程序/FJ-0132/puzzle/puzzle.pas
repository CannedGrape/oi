program puzzle;
	type _p=array[1..30,1..30] of integer;
	var pan,origpan:_p;
		  _E,_S,_T:array[1..500] of array[1..2] of integer;
		  E,S,T:array[1..2] of integer;
		  n,m,q:integer;
		  nm:longint;
		  min:integer;
		  debugdg:integer;
		  debugmode:boolean;
		

	procedure init();
	var i,j:integer;
	begin
		debugmode:=FALSE;
		assign(input,'puzzle.in');assign(output,'puzzle.out');
		reset(input);rewrite(output);
		readln(n,m,q);
		nm:=n*m;
		for i:=1 to n do
		begin
			for j:=1 to m do
				read(origpan[i,j]);
			readln;
		end;
		for i:=1 to q do
			readln(_E[i][1],_E[i][2],_S[i][1],_S[i][2],_T[i][1],_T[i][2]);

		if debugmode then
		begin
			{debug code begin}
			for i:=1 to n do
			begin
				for j:=1 to m do
					write(origpan[i,j], ' ');
				writeln;
			end;
			writeln;writeln;	
			{debug code end}
		end;
			
	end;
	
		
		
	procedure exportexample();
	begin
		writeln('2');
		writeln('-1');
	end;
		

		
	procedure search(oldx,oldy,x,y:integer;first:boolean);
	var i,j,time,w,he,heh:integer;
	begin
		time:=0;
		if(debugdg>nm) then begin time:=-1; exit; end;
		if (pan[x,y]>0) and (pan[x,y]<3) then
		begin
			{
				pan[x,y]=0    fixed
				pan[x,y]=1     moveable
				pan[x,y]=2     blank
				pan[x,y]=3    selected
			}
			if (pan[x,y]=1) or (pan[x,y]=2) then
			begin
				for i:=x-1 to x+1 do
					for j:=y-1 to y+1 do
						if
							not(
								(i<1)
								or
								(i>m)
								or
								(j<1)
								or
								(j>n)
							)
							and
							not(
								(
									(i=x-1)
								and
									(j<>y)
								)
								or
								(
									(i=x+1)
								and
									(j<>y)
								)
							)
							and
							not((i=x) and (j=y))
						then
						begin
							if (pan[i,j]<>pan[x,y]) and (pan[i,j]>0) then
							begin
								{only blank and moveable|selected can change their position}
								
								if (i<>oldx) and (j<>oldy) and ((pan[x,y]=2) and ((pan[i,j]=1) or (pan[i,j]=3))) or ((pan[i,j]=2) and ((pan[x,y]=1) or (pan[x,y]=3))) then
								begin
									if debugmode then begin
										{debug code begin}
										writeln('before moved:');
										writeln('pan[i,j]=',pan[i,j],' pan[x,y]=',pan[x,y],' i=',i,' j=',j,' x=',x,' y=',y,' T[1]=',t[1],' T[2]=',T[2]);
										for he:=1 to n do
										begin
											for heh:=1 to m do
												write(pan[he,heh], ' ');
											writeln;
										end;
										writeln;writeln;
										{debug code end}
									end;
								
									w:=pan[i,j];
									pan[i,j]:=pan[x,y];
									pan[x,y]:=w;
									inc(time);
									{swap 2 items}
								
									if debugmode then begin
										{debug code begin}
										writeln('moved:');
										writeln('pan[i,j]=',pan[i,j],' pan[x,y]=',pan[x,y],' i=',i,' j=',j,' x=',x,' y=',y,' T[1]=',t[1],' T[2]=',T[2]);
										for he:=1 to n do
										begin
											for heh:=1 to m do
												write(pan[he,heh], ' ');
											writeln;
										end;
										writeln;writeln;writeln;
										{debug code end}
									end;
										
									if not((pan[x,y]=3) and (T[1]=x) and (T[2]=y)) then
									begin
										inc(debugdg);
									
										if debugmode then begin
											{debug code begin}
											writeln('debug=',debugdg);
											{debug code end}
										end;
										
										search(x,y,i,j,FALSE);
										{then search again}
										dec(time);
										dec(debugdg);
										pan[x,y]:=pan[i,j];
										pan[i,j]:=w;
									end
									else
									begin
										inc(time);
										if debugmode then begin
											{debug code begin}
											writeln('found! time=',time);
											{debug code end}
										end;
										if min>time then min:=time;
										exit;
									end;
								end;
							end;
						end;
			end;
		end;
	end;
	
	procedure main();
	var i,he,heh:integer;
	begin
		for i:=1 to q do
		begin
			E:=_E[i];
			S:=_S[i];
			T:=_T[i];
			pan:=origpan;
			pan[E[1],E[2]]:=2;
			pan[S[1],S[2]]:=3;
			
			min:=32767;
			debugdg:=0;
			if debugmode then
			begin
				{debug code begin}
				{writeln('a new record!');
				for he:=1 to n do
				begin
					for heh:=1 to m do
					begin
						if(pan[he,heh]=2) then
							write('□')
						else if (pan[he,heh]=1) then
							write('△')
						else if (pan[he,heh]=0) then
							write('■')
						else if (pan[he,heh]=3) then
							write('◆');
						write(' ');
					end;
					writeln;
				end;
					
				writeln;writeln;
				writeln('T= ', T[1],' ',T[2]);
				writeln('E= ', E[1],' ',E[2]);
				writeln('S= ', S[1],' ',S[2]);}
				{debug code end}		
			end;
			if ((T[1]=S[1]) and (T[2]=S[2])) then min:=0;
			if (pan[T[1],T[2]]>0) and not((T[1]=S[1]) and (T[2]=S[2])) then search(0,0,E[1],E[2],TRUE);
			if min=32767 then min:=-1;
			writeln(min);
		end;
	end;
	
	procedure term();
	begin
		close(input);close(output);
	end;
	
	
	
	begin
		init();
		main();
		term();
	end.
