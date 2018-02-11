program circle;
	const n_max=1000000;
	var n,m,x:longint;
		  k:int64;
		  friends,friends_old:array[0..n_max] of longint;
		  test:ansistring;


	procedure init();
	var i:longint;
		  c:int64;
	begin
		assign(input,'circle.in');assign(output,'circle.out');
		reset(input);rewrite(output);
		read(n,m,k,x);
		for i:=0 to n do friends[i]:=i;
		test:='1';
		c:=0;
		
		while(c<k) do begin 
			test:=test+'0';
			inc(c);
		end;
		
		val(test,k);
		
		k:=k mod n;
	end;
	
	procedure move(i:longint);
	var j:longint;
	begin
	
		if i-m>=0 then 
			friends[i]:=friends_old[i-m]
		else
			friends[i]:=friends_old[n-m+i];
		
		if i+1<n then 
			move(i+1)
		else if i+1>n then 
			move(0);
		
	end; 
	
	
	procedure main();
	var j:longint;
		  i:int64;
	begin
		friends_old:=friends;
		i:=1;
		while(i<k) do 
		begin
			move(0);
			friends_old:=friends;
			{writeln;
			writeln(i);
			for j:=0 to n-1 do writeln('friends[',j,'] = ',friends[j]);}
			i:=i+1;
		end;
		writeln(friends[x]);
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