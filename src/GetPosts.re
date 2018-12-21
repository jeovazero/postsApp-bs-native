open BsReactNative;
open Belt.Option;
let str = ReasonReact.string;

let makePost = (author, text) =>
  Post.{author, text};

let postsContainer = Style.(style([
  display(Flex),
  alignItems(Center),
  paddingBottom(Pt(40.)),
  zIndex(1)
]));

let postStyle = Style.(style([
  marginBottom(Pt(10.)),
  marginTop(Pt(10.))
]));

module GetPosts = [%graphql
  {|
  query getAllPosts{
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
    <GetPostsQuery>
      ...{
           ({result}) =>
              (
                <ScrollView contentContainerStyle=postsContainer>{
                  switch (result) {
                    | Loading => <Text> { "Loading" |> str }</Text>;
                    | Error(error) => <Text> {error##message |> str} </Text>;
                    | Data(response) =>
                        (
                          response##getPosts
                          -> mapWithDefault( ReasonReact.null, posts => {
                            (
                              posts
                              |> Array.mapi((index, post) => {
                                  post
                                  -> mapWithDefault( ReasonReact.null, p => {
                                    <Post
                                      key=unwrap(p##id, index |> string_of_int)
                                      style=postStyle
                                      post=makePost(unwrap(p##author, "anon"), unwrap(p##text, "")) />
                                  })
                              })
                            ) |> ReasonReact.array;
                          })
                        )
                  }
                }</ScrollView>
              )
          
         }
    </GetPostsQuery>;
  },
};