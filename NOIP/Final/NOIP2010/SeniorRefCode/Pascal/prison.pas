program prison(input,output);
  const
    maxn=20000;
    maxm=100000;
  type
    link=^edge;
    edge=record
      v,w:longint;
      next:link;
    end;
  var
    n,m,ans:longint;
    g:array[1..maxn] of ^edge;
    a:array[1..maxm] of longint;
    q:array[1..maxm*10] of longint;
    color:array[1..maxn] of longint;

  procedure add(u,v,w:longint);
    var
      p:link;
    begin
      new(p);
      p^.v:=v;p^.w:=w;p^.next:=g[u];
      g[u]:=p;
    end;

  procedure init;
    var
      i,u,v,w:longint;
    begin
      fillchar(g,sizeof(g),0);
      assign(input,'prison.in');reset(input);
      readln(n,m);
      for i:=1 to m do begin
        readln(u,v,w);
        add(u,v,w);
        add(v,u,w);
        a[i]:=w;
      end;
      close(input);
    end;

  procedure over;
    begin
      assign(output,'prison.out');rewrite(output);
      writeln(ans);
      close(output);
    end;

  procedure qsort(l,r:longint);
    var
      i,j,k,tmp:longint;
    begin
      i:=l;j:=r;k:=a[(i+j) shr 1];
      while i<=j do begin
        while a[i]<k do inc(i);
        while a[j]>k do dec(j);
        if i<=j then begin
          tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
          inc(i);dec(j);
        end;
      end;
      if i<r then qsort(i,r);
      if l<j then qsort(l,j);
    end;

  function bfs(weight:longint):boolean;
    var
      f,r,k,u,v,w:longint;
      p:link;
    begin
      fillchar(color,sizeof(color),0);
      for k:=1 to n do if color[k]=0 then begin
        f:=1;r:=0;
        inc(r);q[r]:=k;color[k]:=1;
        while f<=r do begin
          u:=q[f];inc(f);
          p:=g[u];
          while p<>nil do begin
            v:=p^.v;w:=p^.w;
            if w>weight then begin
              if (color[v]<>0)and(color[v]=color[u]) then
                exit(false)
              else if (color[v]=0) then begin
                color[v]:=color[u] mod 2+1;
                inc(r);q[r]:=v;
              end;
            end;
            p:=p^.next;
          end;
        end;
      end;
      exit(true);
    end;

  procedure main;
    var
      l,r,mid:longint;
    begin
      qsort(1,m);
      l:=1;r:=m;
      while l<=r do begin
        mid:=(l+r) shr 1;
        if bfs(a[mid]) then r:=mid-1
        else l:=mid+1;
      end;
      if r<=0 then ans:=0
      else ans:=a[l];
    end;

  begin
    init;
    main;
    over;
  end.
