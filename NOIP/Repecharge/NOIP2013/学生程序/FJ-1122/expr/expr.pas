var
  a:array[1..100000] of longint;
  s,v,o:ansistring;
  ans,i,j,len,u,code,k,e:longint;
  b:boolean;
begin
assign(input,'expr.in');
assign(output,'expr.out');
reset(input);
rewrite(output);
  readln(s);
  s:=s+'+';
  len:=length(s);
  v:='';
  b:=false;
  k:=1;
  for i:=1 to len do
   begin
     if s[i]='+' then
     begin
     code:=length(v);
     o:='';
       if code>4 then begin v:=v[1]+v[2]+v[3]+v[4]; code:=4;end;
     for j:=1 to code do o:=v[j]+o;
     if b=true then
     begin val(o,e,code);k:=k*e mod 10000;inc(u);a[u]:=k;b:=false;k:=1;end
     else begin inc(u);val(o,a[u],code);end;v:='';continue;end;
     if s[i]='*' then
     begin
     code:=length(v);
     o:='';
     if code>4 then begin v:=v[1]+v[2]+v[3]+v[4]; code:=4;end;
     for j:=1 to code do o:=v[j]+o;
     b:=true;val(o,e,code);k:=k*e mod 10000;v:='';continue; end;
     v:=s[i]+v;
//     writeln(v,' ',i);
   end;
//   writeln(a[3]);
// if b=true then begin inc(u);a[u]:=k;b:=false;end;
   for i:=1 to u do ans:=(ans+a[i]) mod 10000;
   writeln(ans);
close(input);
close(output);
end.
