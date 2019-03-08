var
 s:string;
 i,sc,len,j,k,x,y,z,ans:longint;
 sz:array[1..100020] of longint;
 flag:boolean;
begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
 readln(s);
 s:=s+'+';
 j:=0;
 k:=0;
 sc:=0;
 i:=1;
 flag:=true;
 while i<=length(s) do
  begin
   if (s[i]>='0') and (s[i]<='9')
    then
     inc(sc)
    else
     begin
      if (flag=false) and (i<length(s))
       then
        begin
         val(copy(s,1,sc),x);
         x:=x mod 10000;
         delete(s,1,sc);
         sz[j]:=(sz[j]*x) mod 10000;
         flag:=true;
         sc:=0;
         i:=0;
        end;
      if (flag=false) and (i=length(s))
       then
        begin
         val(copy(s,1,sc),x);
         x:=x mod 10000;
         delete(s,1,sc);
         sz[j]:=(sz[j]*x) mod 10000;
         flag:=true;
         sc:=0;
         i:=0;
        end;
      if s[i]='+'
       then
        begin
         inc(j);
         val(copy(s,1,sc),sz[j]);
         delete(s,1,sc+1);
         sz[j]:=sz[j] mod 10000;
         inc(k);
         sc:=0;
         i:=0;
        end;
      if s[i]='*'
       then
        begin
         inc(j);
         val(copy(s,1,sc),sz[j]);
         delete(s,1,sc+1);
         sz[j]:=sz[j] mod 10000;
         flag:=false;
         i:=0;
         sc:=0;
        end;
     end;
   inc(i);
  end;
 ans:=0;
 for i:=1 to k+1 do
  ans:=(ans+sz[i]) mod 10000;
 writeln(ans);
 close(input);
 close(output);
end.
