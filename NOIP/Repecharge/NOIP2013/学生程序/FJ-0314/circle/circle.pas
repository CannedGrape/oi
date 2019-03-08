var ans,n,m,k,x,t:int64;
  function find(x,y:int64):int64;
    begin
      if x=1 then exit(10 mod y);
      if x=0 then exit(1 mod y);
      if x mod 2=0 then find:=sqr(find(x div 2,y))mod y
      else find:=((sqr(find(x div 2,y)) mod y)*10)mod y;
    end;
  begin
    assign(input,'circle.in');reset(input);
    assign(output,'circle.out');rewrite(output);
    read(n,m,k,x);
    t:=find(k,n);
    ans:=(x mod n+(t*(m mod n))mod n)mod n;
    write(ans);
    close(input);
    close(output);
  end.