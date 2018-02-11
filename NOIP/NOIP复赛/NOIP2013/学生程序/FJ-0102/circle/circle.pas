var n,m,x,k,ans:longint;
    v:boolean;
    p,q:array[0..1000000]of longint;

procedure work;
var tt,a,r:longint;
begin
 v:=false;
 p[1]:=10 mod n;
 q[p[1]]:=1;
 for a:=2 to k do
  begin
   p[a]:=(p[a-1]*10) mod n;
   if p[a]=0 then exit;
   if q[p[a]]=0 then q[p[a]]:=a else
    begin
     v:=true;
     tt:=a-q[p[a]];
     if k mod tt>0 then ans:=p[k mod tt] else ans:=p[tt];
     break;
    end;
  end;
 if not v then ans:=p[k];
end;

begin
 assign(input,'circle.in');
 assign(output,'circle.out');
 reset(input);
 rewrite(output);
 readln(n,m,k,x);
 ans:=0;
 work;
 ans:=(ans*m) mod n;
 ans:=(ans+x) mod n;
 writeln(ans);
 close(input);
 close(output);
end.
