var i,j,l,m,n:longint;
    a:array[0..100000] of longint;
    k,x,y,t:qword;
    z:char;
    s1,s2,s,f:string;
    begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
   readln(s);
    for i:=1 to length(s) do
     begin
      if (s[i]='*')or(s[i]='+') then
       begin inc(t);a[t]:=i;
       end;
     end;
    a[t+1]:=length(s)+1;
    j:=1; f:=s;
    for i:=1 to t do
     begin
     if s[a[i]]='*' then
      begin
        s1:=copy(s,j,a[i]-j);
          val(s1,x,l);j:=1+a[i];
          s2:=copy(s,a[i]+1,a[i+1]-j);
          val(s2,y,l);
         k:=(x*y) mod 10000;
          str(k,s1);
          if i<> t then
          j:=a[i-1]+1 else j:=a[i-1];
          delete(s,j,a[i+1]-j);
         s:=s+'+'+s1;
         j:=a[i]+1;
      end else j:=a[i]+1;
      end;
       fillchar(a,sizeof(a),0);
       l:=1; t:=0;
     for i:=1 to length(s) do
      begin
       if s[i]='+' then
        begin
         a[l]:=i;
         inc(l);
        end;
        if s[i]=' ' then delete(s,i,1);
       end;
       a[l]:=length(s);
       l:=l-1;j:=1;
       for i:=1 to l do
        if s[a[i]]='+' then
         begin
          if i=1 then begin
          s1:=copy(s,j,a[i]-j);
          val(s1,x,l);     t:=x;end;
          s2:=copy(s,a[i]+1,a[i+1]-j);
          val(s2,y,l);
          t:=(t mod 10000)+(y mod 10000) mod 10000;
          j:=1+a[i];
         end;
       write(t);
   close(input);
   close(output);
  end.



