open BsReactNative;
open Belt.Option;
let str = ReasonReact.string;

module GetPosts = [%graphql
  {|
  query{
      getPosts{
        author
        text
        id
      }
  }
|}
];

module GetPostsQuery = ReasonApollo.CreateQuery(GetPosts);
let txt = (str, key) => <Text key=string_of_int(key)>{ReasonReact.string(str)}</Text>;
let component = ReasonReact.statelessComponent("MyQuery");
let unwrap = (value, default) => value -> mapWithDefault(default, i => i);

let make = _children => {
  ...component,
  render: _ => {
    <GetPostsQuery >
      ...{
           ({result}) =>
            <View>
              (
                switch (result) {
                  | Loading => <Text> { "Loading" |> str }</Text>;
                  | Error(error) => <Text> {error##message |> str} </Text>;
                  | Data(response) =>
                    <View>
                      (
                        response##getPosts
                        -> mapWithDefault( ReasonReact.null, posts => {
                          (
                            posts
                            |> Array.mapi((index, post) => {
                                <View key={ index |> string_of_int}>
                                  {
                                    post
                                    -> mapWithDefault( ReasonReact.null, p => {
                                      <View>
                                          <Text>{ unwrap(p##author, "") |> str}</Text>
                                          <Text>{ unwrap(p##text, "") |> str}</Text>
                                          <Text>{ unwrap(p##id, "") |> str}</Text>
                                      </View>
                                    })
                                  }
                                </View>
                            })
                          ) |> ReasonReact.array;
                        })
                      )
                    </View>
                }
              )
            </View>
         }
    </GetPostsQuery>;
  },
};