var a:array[0..1005]of longint;
    i,j,l,r,n,num,ans,k:longint;
    flag:boolean;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  num:=0;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      begin
        if n-i+1<num then break;
        l:=i;r:=j;ans:=2;
        if a[l]<a[r] then flag:=true
          else if a[l]>a[r] then flag:=false;
        k:=r+1;
        while k<=n do
          begin
            if flag and (a[r]>a[k]) then
              begin
                l:=r;r:=k;
                flag:=false;
                inc(ans);
              end;
            if (not flag) and (a[r]<a[k]) then
              begin
                l:=r;r:=k;
                flag:=true;
                inc(ans);
              end;
            inc(k);
          end;
        if ans and 1=0 then ans:=ans-1;
        if ans>num then num:=ans;
      end;
  writeln(num);
  close(input);close(output);
end.
