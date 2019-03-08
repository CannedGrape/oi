program block;
	type lb=array[1..2] of integer;
	var n,count:longint;
		  maxh,h:array[1..100000] of integer;
		  debugmode:boolean;
	


	procedure init();
	var i:longint;
	begin
		debugmode:=FALSE;
		assign(input,'block.in');assign(output,'block.out');
		reset(input);rewrite(output);
		readln(n);
		for i:=1 to n do begin h[i]:=0; read(maxh[i]); end;
		count:=0;
		
	end;
	
	procedure exportexample();
	begin
		writeln('5');
	end;
	
	function getLU(_:longint):lb;
	var i:longint;
		  first:boolean;
	begin
		getLU[1]:=0;
		getLU[2]:=0;
		first:=false;
		for i:=1 to n do begin
			if (maxh[i]>=_) and (h[i]<maxh[i]) then
				if first=true then
					getLU[2]:=i
				else
				begin
					getLU[1]:=i;
					getLU[2]:=i;
					first:=true;
				end
			else if first=true then exit;
		end;
	end;
		
	procedure scan(k:longint);
	var i:longint;
		  w:lb;
	begin
		w:=getLU(k);
		if w[1]>0 then 
		begin
			inc(count);
			for i:=w[1] to w[2] do inc(h[i]);
			if debugmode then 
			begin
				for i:=1 to n do begin write(h[i]); end;
				writeln;
			end;
			scan(k);
			scan(k+1);
		end;
	end;
		
		
		
	procedure main();
	begin
		scan(1);
		writeln(count);
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