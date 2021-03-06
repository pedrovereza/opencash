// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include <generated/TransactionsMeta-odb.hxx>

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/view-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/view-result.hxx>

namespace odb
{
  // TransactionsMeta
  //

  bool access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _count
    //
    t[0UL] = false;

    return grew;
  }

  void access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i)
  {
    using namespace sqlite;

    sqlite::statement_kind sk (statement_select);
    ODB_POTENTIALLY_UNUSED (sk);

    std::size_t n (0);

    // _count
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i._count_value;
    b[n].is_null = &i._count_null;
    n++;
  }

  void access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::
  init (view_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _count
    //
    {
      // From TransactionsMeta.h:22:37
      ::std::size_t v;

      sqlite::value_traits<
          ::std::size_t,
          sqlite::id_integer >::set_value (
        v,
        i._count_value,
        i._count_null);

      // From TransactionsMeta.h:22:37
      o.setCount (v);
    }
  }

  access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::query_base_type
  access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::
  query_statement (const query_base_type& q)
  {
    query_base_type r (
      "SELECT "
      "count(*) ");

    r += "FROM \"transactions\"";

    if (!q.empty ())
    {
      r += " ";
      r += q.clause_prefix ();
      r += q;
    }

    return r;
  }

  result< access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::view_type >
  access::view_traits_impl< ::opencash::model::TransactionsMeta, id_sqlite >::
  query (database&, const query_base_type& q)
  {
    using namespace sqlite;
    using odb::details::shared;
    using odb::details::shared_ptr;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_view<view_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.image_binding ());

    if (im.version != sts.image_version () || imb.version == 0)
    {
      bind (imb.bind, im);
      sts.image_version (im.version);
      imb.version++;
    }

    const query_base_type& qs (query_statement (q));
    qs.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        qs.clause (),
        false,
        true,
        qs.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::view_result_impl<view_type> > r (
      new (shared) sqlite::view_result_impl<view_type> (
        qs, st, sts, 0));

    return result<view_type> (r);
  }
}

#include <odb/post.hxx>
