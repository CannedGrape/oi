program ooo;
var s,s1:string;
    i,lens,h,p,j,q,k,e:longint;
    o:char;
    a:array[1..255]of longint;

    begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  k:=1;
  read(s);
  lens:=length(s);
  for i:=1 to lens do
  begin
     o:=s[i];
     if (s[i]='*')or(s[i]='+') then
     begin
      inc(j);
     val(s1,q);
     a[i-1]:=q mod 10000;

     if j=1 then p:=length(s1);
      s1:='';
     end
     else s1:=s1+s[i];
  end;
  val(s1,q);
  a[lens]:=q mod 10000;
  E:=length(s1);

  for i:=1 to lens do
  begin
    if (s[i]<>'+')and(s[i]<>'*')then
    begin
      if (i=lens)and(s[i-e]='+') then h:=(h+(a[i])mod 10000)mod 10000
      else
      begin
      if (s[i+1]='+')and(s[i-1]<>'*') then h:=(h+a[i] mod 10000)mod 10000;
      if s[i+1]='*' then h:=(h+((a[i]mod 10000)*(a[i+2]mod 10000))mod 10000)mod 10000;
    end;
    end; end;
  write(h);
  close(input);close(output);
end.
