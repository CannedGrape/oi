program day1;
  var  n,m,x,k,a:int64;
		begin
			assign(input,'circle.in');
			reset(input);
			assign(output,'circle.out');
	                rewrite(output);
                        read(n,m,k,x) ;
                        a:=1;
                        repeat
                        begin
                         a:=a*10;
                         dec(k);
						if (m*a )mod n= 0 then a:=1;
                        end
                        until k=0;
                        x:=(x+m* a ) mod n;
			writeln(x);
			close(input);
			close(output);
		end.
