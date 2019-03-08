var 
	n,m,k,x,ans,tmp:int64;
	flg:boolean;

procedure freopen;
begin
	assign(input,'circle.in');reset(input);
	assign(output,'circle.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;

begin
	freopen;
	readln(n,m,k,x);
	ans:=n*m;
	tmp:=10000000000 mod ans;
	flg:=false;
	if tmp=0 then writeln(x)
	else 
		begin
			while x+m>n-1 do 
				begin
					x:=x+m-n-1;
					flg:=true;
				end;
			if not flg then 
				x:=x+m;
			writeln(x);
		end;
	readln;
	freclose;
end.