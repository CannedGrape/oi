var
   h,sum,i,j,l:longint;
   s,t:string;
   a:array[1..100000] of longint;
   _or:boolean;
function cutt(st:string):longint;
var
   k:longint;
begin
    k:=length(st);
    cutt:=ord(st[k])-48;
    if k-1>0 then begin
    cutt:=cutt+(ord(st[k-1])-48)*10;
      if k-2>0 then begin
        cutt:=cutt+(ord(st[k-2])-48)*100;
        if k-3>0 then begin
          cutt:=cutt+(ord(st[k-3])-48)*1000;
     end;end;end;
end;
function cut(m:longint):longint;
var
   ss:string;
begin
   str(m,ss);
   cut:=cutt(ss);
end;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  l:=length(s);
  i:=0;
  h:=0;sum:=0;
  _or:=false;
  repeat
    inc(i); t:='';
    if s[i] in ['0'..'9'] then begin
      repeat
        t:=t+s[i];
        inc(i);
      until not(s[i] in ['0'..'9']);
      inc(h);
      a[h]:=cutt(t);
      end;
      if _or then begin
        a[h-1]:=cut(a[h]*a[h-1]);
        a[h]:=0;dec(h);
        end;
      if s[i]='*' then _or:=true else _or:=false;
  until i>l;





  for i:=1 to h do
  begin
  sum:=sum+a[i];
  if i mod 100=0 then sum:=cut(sum);
  end;
  writeln(cut(sum));
  close(input);
  close(output);
end.

