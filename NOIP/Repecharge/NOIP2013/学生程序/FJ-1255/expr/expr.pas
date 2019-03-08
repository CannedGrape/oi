program expr;
  var c:array[1..100000] of longint;
      s:string;
      s1:array[1..100000] of string;
      i,j,v,w,t,p,k,len:longint;s2:string;
  begin
    assign(input,'expr.in');
    reset(input);
    assign(output,'expr.out');
    rewrite(output);
    readln(s);
    t:=1;
    for i:=1 to length(s) do
      begin
        if (s[i]='*') or (s[i]='+') then begin
        inc(t);
        s1[t]:=s[i];
        inc(t);
        end else
        s1[t]:=s1[t]+s[i];
      end;
    i:=1;
    while i<=t do
      begin
        if s1[i]='*' then begin
          val(s1[i+1],v);
          c[p]:=c[p]*v;
          i:=i+2;
        end else  begin
        inc(p);
        if s1[i]='0' then c[p]:=0 else
        val(s1[i],c[p]);
        inc(i);
      end;
    end;
  for i:=1 to p do  k:=k+c[i];
  str(k,s2);
  len:=length(s2);
  if len>4 then begin
    for i:=len-3 to len-1 do
      if s2[i]<>'0' then begin
        for j:=i to len-1 do write(s2[j]);
        break;
      end;
    write(s2[len]);
  end else
    for i:=1 to len do write(s2[i]);
   close(input);
   close(output);
  end.


