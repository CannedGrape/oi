var
            n,p,lar,i:longint;
            a,s,c:array [1..1000000] of longint;
function max(q1,q2:longint):longint;
begin
        if q1>q2 then max:=q1 else max:=q2;
end;


begin
       assign(input,'number.in');
       reset(input);
       assign(output,'number.out');
       rewrite(output);
          readln(n,p);
          for i:=1 to n do read(a[i]);
          if n>1 then
           begin
            s[1]:=a[1];
            for i:=2 to n do s[i]:=max(s[i-1],s[i-1]+a[i]);
            c[1]:=s[1];
            c[2]:=s[1]+c[1];
            if n>2 then
                begin
                  for i:=3 to n do c[i]:=max(c[i-1],c[i-1]+s[i-1]);
                  lar:=c[1];
                  for i:=2 to n do
                      begin
                         lar:=max(lar,c[i]);

                      end;
                  writeln(lar mod p);
                end else writeln(max(c[1],c[2]));
           end else writeln(a[1]);
      close(input);
       close(output);
end.
