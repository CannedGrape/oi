program classroom;
var i,j,n,m:longint;
    d,s,t,r:array[1..1000000]of int64;
procedure inp;
begin
	assign(input,'classroom.in');assign(output,'classroom.out');reset(input);rewrite(output);
end;
procedure outp;
begin
	close(input);close(output);halt;
end;

procedure init;
begin
     readln(n,m);
     for i:=1 to n do read(r[i]);
     for i:=1 to m do readln(d[i],s[i],t[i]);
end;

begin
	inp;
	init;
        for i:=1 to m do
            for j:=s[i] to t[i] do begin
                r[j]:=r[j]-d[i];
                if r[j]<0 then begin
                   writeln('-1');
                   writeln(i);
                   outp;
                end;
            end;
        writeln('0');
        outp;
end.
