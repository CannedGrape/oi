{ NOI 2002 Day 1 Problem 3 Dragon   by  Ziqing Mao }
program Dragon;
  const MaxN=500;
  var g:array[0..MaxN,0..MaxN]of longint;
      v:array[0..MaxN]of boolean;
      brother,son:array[1..MaxN]of integer;
      h:array[0..1,0..MaxN,0..MaxN]of longint;
      n,m,need:integer;
  procedure Init;
    var f:text; i,j,p:integer; k:longint;
      begin
        assign(f,'dragon.in');
        reset(f);
        readln(f,n,m,need);
        fillchar(g,sizeof(g),255);
        for p:=1 to n-1 do
          begin
            readln(f,i,j,k);
            g[i,j]:=k; g[j,i]:=k;
          end;
        close(f);
      end;
  procedure Make(now:integer);
    var i:integer;
      begin
        v[now]:=true;
        for i:=n downto 1 do
          if (not v[i]) and (g[now,i]>=0) then
            begin
              brother[i]:=son[now];
              son[now]:=i;
              Make(i);
            end;
      end;
  function Get(now,father,need:integer; head:integer):longint;
    var p,q,c,min:longint; k:integer;
      begin
        if now=0 then
          begin
            if need=0 then Get:=0 else Get:=-1;
            exit;
          end;
        if h[head,now,need]<>-1 then
          begin
            Get:=h[head,now,need];
            exit;
          end;
        min:=maxlongint;
        for k:=0 to need do
          begin
            p:=Get(brother[now],father,k,head);
            if k=need then q:=-1 else q:=Get(son[now],now,need-k-1,1);
            if (p>=0) and (q>=0) then
              begin
                if head=1 then c:=p+q+g[father,now] else c:=p+q;
                if c<min then min:=c;
              end;
            q:=Get(son[now],now,need-k,0);
            if (p>=0) and (q>=0) then
              begin
                if (head=0) and (m=2) then c:=p+q+g[father,now] else c:=p+q;
                if c<min then min:=c;
              end;
          end;
        if min=maxlongint then Get:=-2 else Get:=min;
        if min=maxlongint then h[head,now,need]:=-2 else h[head,now,need]:=min;
      end;
  procedure Main;
    var now:integer; ans:longint; f:text;
      begin
        fillchar(v,sizeof(v),0);
        Make(1);
        fillchar(h,sizeof(h),255);
        if need+m-1>n then ans:=-1 else ans:=Get(son[1],1,need-1,1);
        assign(f,'dragon.out');
        rewrite(f);
        writeln(f,ans);
        close(f);
      end;
    begin
      Init;
      Main;
    end.
