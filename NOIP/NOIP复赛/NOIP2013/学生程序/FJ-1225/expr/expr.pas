var a:array[0..100000] of char;
    b,c:array[0..100000] of longint;
    n:ansistring;
    p:boolean;
    k,t,s,i,j,l:longint;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(n);
  while i<length(n) do
  begin
    inc(i);
    if (ord(n[i])-48>=0) and (ord(n[i])-48<=9) then begin
                                                      inc(s);
                                                      k:=ord(n[i])-48;
                                                      b[s]:=k;
                                                    end
    else begin
           if n[i]='*' then
           begin
             inc(l);
             c[l]:=j+1;
           end;
           inc(j); a[j]:=n[i];
         end;
    while (n[i]<>'+') and (n[i]<>'*') and (i<>length(n)) and (n[i+1]<>'+') and (n[i+1]<>'*') do
    begin
      inc(i);
      k:=k*10+ord(n[i])-48;
      b[s]:=k;
    end;
  end;  i:=0;
  while i<>l do
  begin
    inc(i);
    if b[c[i]]=0 then begin b[c[i]]:=b[c[i]-1];b[c[i]-1]:=0; end;
    b[c[i]]:=b[c[i]]*b[c[i]+1];
    b[c[i]+1]:=0;
  end;i:=0;

  while i<>j+1 do
  begin
    inc(i); t:=t+b[i];
  end;
  str(t,n); i:=0;
  if length(n)<=4 then write(n)
  else
  begin
    for i:=length(n)-3 to length(n) do
    begin
      if (n[i]<>'0') then p:=true;
      if p then write(n[i]);
    end;
  end;
  close(input);close(output);
end.




