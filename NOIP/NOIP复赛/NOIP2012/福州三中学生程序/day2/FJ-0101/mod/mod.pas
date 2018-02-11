program md;
var i,j,m,n,s:longint;
    a,b,ans:qword;
    bi:boolean;
procedure inp;
begin
	assign(input,'mod.in');assign(output,'mod.out');reset(input);rewrite(output);
end;
procedure outp;
begin
	close(input);close(output);halt;
end;

procedure init;
begin
     readln(a,b);
     ans:=1;
end;

begin
	inp;
	init;
        bi:=false;
        while not bi do begin
              if ((ans*a) mod b)=1 then begin
                 writeln(ans);
                 outp;
              end;
              inc(ans);
        end;
	outp;
end.
