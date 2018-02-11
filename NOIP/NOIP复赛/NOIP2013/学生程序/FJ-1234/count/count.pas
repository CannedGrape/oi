var
	n,n1,ans,x,i,ge,shi,bai,qian,wan,shiw,baiwan:longint;

begin
	assign(input,'count.in');
	assign(output,'count.out');
	reset(input);
	rewrite(output);
	read(n,x);
	for i:=1 to n do
                        begin
                           	ge:=i mod 10;
				shi:=(i div 10) mod 10;
				bai:=(i div 100) mod 10;
				qian:=(i div 1000) mod 10;
				wan:=(i div 10000) mod 10;
				shiw:=(i div 100000) mod 10;
				baiwan:=(i div 1000000) mod 10;
                        	if ge=x then inc(ans);
			        if shi=x then inc(ans);
				if bai=x then inc(ans);
			        if qian=x then inc(ans);
				if wan=x then inc(ans);
				if shiw=x then inc(ans);
				if baiwan=x then inc(ans);
			end;
        writeln(ans);
	close(input);
	close(output);
end.
