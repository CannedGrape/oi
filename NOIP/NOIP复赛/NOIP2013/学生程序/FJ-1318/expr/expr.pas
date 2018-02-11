program kjl;
  var l,n,k,i,j:integer;
      m:string;
      f1,f2:text;
      begin
      assign(f1,'expr.in');
      assign(f2,'expr.out');
      reset(f1);
      rewrite(f2);
      read(f1,i);
      write(i);
      close(f1);
      close(f2);
      end.