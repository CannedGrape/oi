program truck;


	{read variables;}
	var n,m:longint;
		  maps:array[1..10000,1..10000] of longint;
		  press:array[1..10000,1..10000] of boolean;
		  q:longint;
		  t_x,t_y:array[1..30000] of integer;
		  
	{runtime global variables;}
		  x,y,min,max:longint;

	procedure search(roady:integer);
	var i,j:longint;
	begin
		if roady<>x then
			for i:=m downto 1 do
				if (maps[i,roady]<>0) and (press[i,y]=FALSE) then
				begin
					if min>maps[i,roady] then min:=maps[i,roady];
					if max<min then max:=min;
					press[i,y]:=TRUE;
					search(i);
				end;
	end;	  
		  
	
	

	procedure init();
	var i:longint;
		  t1,t2,t3:longint;
	begin
		fillchar(maps,sizeof(maps),0);
		fillchar(t_x,sizeof(t_x),0);
		fillchar(t_y,sizeof(t_y),0);
		assign(input,'truck.in');assign(output,'truck.out');
		reset(input);rewrite(output);
		readln(n,m);
		
		for i:=1 to m do
		begin
			readln(t1,t2,t3);
			maps[t1,t2]:=t3;
			maps[t2,t1]:=t3;
		end;
		
		{for i:=1 to m do
		begin	
			for t1:=1 to m do
				write(maps[i,t1], ' ');
			writeln;
		end;}
		
		readln(q);
		
		for i:=1 to q do
		begin
			readln(t1,t2);
			t_x[i]:=t1;
			t_y[i]:=t2;
		end;	
		
	end;
		

	
	procedure main();
	var i:longint;
	begin
		for i:=1 to q do
		begin
			x:=t_x[i];y:=t_y[i];
			min:=32767;
			max:=-1;
			fillchar(press,sizeof(press),FALSE);
			search(y);
			if max=32767 then max:=-1;
			writeln(max);
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