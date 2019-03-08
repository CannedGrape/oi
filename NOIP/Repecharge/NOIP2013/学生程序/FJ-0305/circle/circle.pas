var n,m,k,x,shi,i,dy,dg:longint;a:array[0..1000001]of longint;
 function gcd(s1,s2:longint):longint;
  begin
  if s1 mod s2=0 then gcd:=s2 else
       gcd:=gcd(s2,s1 mod s2);
  end;

begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
 readln(n,m,k,x);
 shi:=1;
 for i:=0 to n-1 do a[i]:=i;
 if k<=7 then begin
                 for i:=1 to k do shi:=shi*10;
                 for i:=1 to shi do
                      begin a[x]:=(a[x]+m)mod n;end;
               end else
               begin
                    dy:=gcd(n,m);dg:=(n div dy)*m;
                        for i:=1 to k do shi:=(shi*10)mod dg;
                        for i:=1 to shi do
                              begin a[x]:=(a[x]+m)mod n;end;
                end;

 write(a[x]);
 close(input);
 close(output);
 end.
