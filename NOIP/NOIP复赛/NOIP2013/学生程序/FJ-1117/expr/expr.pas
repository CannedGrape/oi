program expr;
  var i,j,len,x,u,ans,k,code:longint;
      s:ansistring;
      c:string;
      f:array[1..100001]of boolean;
      a:array[1..100001]of string;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  reset(output);
  read(s);
  len:=length(s);
  i:=1;ans:=0;j:=1;
  fillchar(f,sizeof(f),true);
  while i<=len+1 do
    begin
      if s[i]='+'then
        begin
          a[j]:=copy(s,1,i-1);
          j:=j+1;
          delete(s,1,i);
          len:=length(s);
          i:=1;
        end;
      if s[i]='*'then
        f[j]:=false;
      i:=i+1;
    end;
  a[j]:=s;
  for i:=1 to j do
    begin
      if f[i] then
        begin
          delete(a[i],1,k-5);
          val(a[i],x,code);
          ans:=(ans+x)mod 10000;
        end
      else
        begin
          len:=length(a[i]);
          s:=a[i];k:=1;x:=1;
          while k<=len do
            begin
              if s[k]='*' then
                begin
                  c:=copy(s,1,k-1);
                  delete(c,1,k-5);
                  val(c,u,code);
                  x:=(x*u)mod 10000;
                  delete(s,1,k);
                  len:=length(s);
                  k:=1;
                end;
              k:=k+1;
            end;
          val(s,u,code);
          x:=x*u;
          ans:=ans+x;
        end;
    end;
  write(ans);
  close(input);
  close(output);
end. 
