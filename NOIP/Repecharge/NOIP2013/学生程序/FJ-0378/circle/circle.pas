program circle;
var n,m,k,x,ans:int64;

function qm(va,vt,vm:int64):int64;
var vv,tmp:int64;
begin
     if (vt=1) then exit(va)
		 else begin
			 tmp:=1;
			 vv:=vt mod 2;
		     tmp:=qm(va,vt div 2,vm);
		     tmp:=tmp mod vm;		 
		     tmp:=tmp*tmp;
		     tmp:=tmp mod vm;
		     if (vv=1) then
				 begin
			         tmp:=tmp*va;
			         tmp:=tmp mod vm;
			     end;
		     exit(tmp);
         end;
end;

begin
     assign(input,'circle.in');reset(input);
	 assign(output,'circle.out');rewrite(output);
	 readln(n,m,k,x);
	 ans:=qm(10,k,n);
	 ans:=ans mod n;
	 ans:=ans*m;
	 ans:=ans mod n;
	 ans:=ans+x;
	 ans:=ans mod n;
	 writeln(ans);
     close(input);
	 close(output);
end.